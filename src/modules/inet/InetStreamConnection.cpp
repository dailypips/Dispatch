#include "InetStreamConnection.h"
#include <sstream>


namespace dispatch { namespace module { namespace inet {

InetStreamConnection::InetStreamConnection(InetStreamListener* l, FDMonitor::type* mon) :
	monitor(mon),
	listener(l),
	remote_len(0) {
}

void InetStreamConnection::handleSocketEvent(FDMonitorEvent* evnt) {
	string en = FDEvent::getEventNames(evnt->event);
//	cout << "InetStreamConnection: Socket events: " << en << " fd: " << evnt->fd << endl;
	if (evnt->event & POLLIN) {
		readFromSocket();
	}
}

void InetStreamConnection::readFromSocket() {
	ssize_t bufsize = 1024;
	char buf[bufsize];
	memset(buf, 0, bufsize);
	
	int flags = MSG_DONTWAIT;
	ssize_t size;
	int total_read = 0;
	do {
		stringstream msg_buf;
		size = recv(socket, buf, bufsize, flags);
		if (size == -1) {
			if (errno != EAGAIN) {
				cerr << "Error reading from socket: " << strerror(errno) << endl;
			}
		} else {
			total_read += size;
//			cout << "Read " << size << " bytes: " << buf << endl;
			msg_buf.write(buf, size);
			string msg = msg_buf.str();
			if (msg.length()) {
//				cout << "Handterer chunk[" << msg.length() << ": [" << msg << endl;
				handler.handleStreamChunk(msg);
			}
		}
	} while(size > 0);
	if (total_read == 0) {
		/**
		* H�yst sannsynligvis en disconnect
		*/ 
		disconnected();
		return;
	}
}

void InetStreamConnection::disconnected() {
	monitor->unregisterFD(socket);
}

}}} // end namespace