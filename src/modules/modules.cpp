
#include "modules.h"
#include "dlfcn.h"
using namespace std;
using namespace dispatch::config;
using namespace dispatch::config::filter;
namespace dispatch {
namespace module {

ModuleManager::ModuleManager() : 
	NameTimeTaggingOutputSet(cout.rdbuf(), cerr.rdbuf(), clog.rdbuf(), cerr.rdbuf()) {

}

string ModuleManager::getName() {
	return "ModuleManager";
}


void ModuleManager::loadModules(parseDriver &drv, vector<ModuleEntry> &modules) {
	GConfigNodeList mod_blocks = drv.findNodesByName("main", GConfig::BLOCK);

	And load_filter(new Ident("load_modules"), new Type(GConfig::VARIABLE));

	GConfigNodeList load_vars = mod_blocks.findNodesByFilter(&load_filter);
	
	for(int i = 0; i < mod_blocks.size(); i ++) {
		mod_blocks[i]->used(1);	
	}
	err << "Vars " << load_vars.size() << endl;
	err << "Loading modules:" << endl;
	
	for(int i = 0; i < load_vars.size(); i++) {
		GConfigVariableStatement* var = dynamic_cast<GConfigVariableStatement*>(load_vars[i]);
		vector<GConfigScalarVal*> values = var->getValues();
//		cout << "Variable @ " << var << ": " << values.size() << " verdier" << endl;
		for(int j = 0; j < values.size(); j++) {
			string mod_so = values[j]->getStringValue();
			err << " ** " << mod_so << " **" << endl;
			loadModule(mod_so, modules);
			values[j]->used(1);
		}
		load_vars[i]->used(1);
	}

	loadModulesConfig(drv, modules);
}

void ModuleManager::loadModule(string mod_file, vector<ModuleEntry> &modules) {

	void* handle = dlopen(mod_file.c_str(), RTLD_NOW | RTLD_LOCAL);

	if (handle == NULL) {
		err << "Failed loading module " << mod_file << ": " << dlerror() << endl;
		return;
	} else {

	}

	ModuleEntry entry;

	/**
	 * Initalizer
	 */
	void* func = dlsym(handle, "initialize_dispatch_module");

	if (func == NULL) {
		err << "Failed loading constructor from " << mod_file << ": " << dlerror() << endl;
		return;
	}

	entry.create = (FUNC_TYPE(DispatchModule*)) (func);

	/**
	 * Destructor
	 */
	func = dlsym(handle, "destroy_dispatch_module");

	if (func == NULL) {
		err << "Failed loading destructor from " << mod_file << ": " << dlerror() << endl;
		return;
	}

	entry.destroy = (FUNC_TYPE(void, DispatchModule*)) (func);

	/**
	 * Create module-instance
	 */

	DispatchModule* mod = entry.create();

	if (mod == NULL) {
		err << "Failed creating module-instance from " << mod_file << endl;
	}

	err << "Loaded module: " << mod->getModuleName() << endl;
	entry.module = mod;
	modules.push_back(entry);

}

void ModuleManager::loadModulesConfig(parseDriver &drv, vector<ModuleEntry> &modules) {
	out << "Leter etter config til moduler" << endl;
	for(int i = 0; i < modules.size(); i++) {
		DispatchModule* module = modules[i].module;
		string name = module->getModuleName();
		out << "MODULE: " << name << endl;
		/**
		* Dersom modulen e en eventhandler s� m�
		* vi g� p� leiting etter listener-blokke
		* som har spesifisert den her som module.
		*/
		if (module->isEventHandler()) {
			out << name << " confirms it's and event handler" << endl;
			// Match alle noder som er en variabel med
			And handler_config_filter(
				new Type(GConfig::BLOCK), 
				new Contains(new Contains(new And(
					new Type(GConfig::VARIABLE), 
					new Ident("module", true),  
					new Value(name)
				))), 
				new Name("handler")
			);
			GConfigNodeList nodes = drv.findNodesByFilter(&handler_config_filter);
			for(int j = 0; j < nodes.size(); j++) {
				out << "Found node. Name: " << nodes[j]->getNodeName() << " ident: " << nodes[j]->getFullNodeIdent() << endl;
				module->scanConfigNode(nodes[j]);	
			}
		}
		/**
		* Hvis modulen e en event-source s� m� vi p� leiting etter
		* handler-blokke som har den her som module.
		*/
		if (module->isEventSource()) {
			out << name << " confirms it's an event source" << endl;
			And event_source_config_filter(
				new Type(GConfig::BLOCK), 
				new Contains(new Contains(new And(
					new Type(GConfig::VARIABLE), 
					new Ident("module", true),  
					new Value(name)
				))), 
				new Name("listener")
			);
			GConfigNodeList nodes = drv.findNodesByFilter(&event_source_config_filter);
			for(int j = 0; j < nodes.size(); j++) {
				out << "Found node" << endl;
				module->scanConfigNode(nodes[j]);	
			}
	
		}
	}
	out << "Done." << endl;
}

}} // end namespace