
CC:=g++
CFLAGS:=-Wall -ggdb -fPIC

MODULE_CORE=../DispatchModule.o ../../util/Thread.o ../../core/StreamEventListener.o ../../core/EventQueue.o ../../util/FileStat.o ../../util/Mutex.o ../../util/FDMonitor.o

all: ipcmsglistener.so

%.o: %.cpp
	$(CC) $(CFLAGS) -g -c -o $@ $< 

%.cpp: %.h


ipcmsglistener.so: IPCMsgModule.o MsgListener.o $(MODULE_CORE)
	$(CC) $(CFLAGS) -g -fpic -dynamiclib -shared -lpthread -rdynamic -o $@  $^


clean:
	rm -f *.o *.so
