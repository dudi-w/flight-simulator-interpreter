CXX = g++

CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -g3

CPPFLAGS = -I ./includes -I ./../
CXXFLAGS += -I ./../googletest/googletest/include


# LDLIBS += -lcurlpp -lcurl -lgumbo

OBJECTS_SERVER_TEST = serverTest.o src/simulatorServer.o src/TCPsocketFile.o src/TCPserver.o
OBJECTS_CLIENT_TEST = clientTelnetTest.o src/netClient.o src/TCPsocketFile.o src/TCPclient.o
MAIN_TEST = mainTest.o src/simulatorServer.o src/TCPserver.o src/netClient.o src/TCPsocketFile.o src/TCPclient.o
all: serverTest clientTelnetTest mainTest

mainTest : $(MAIN_TEST)
	g++ $(MAIN_TEST) -o mainTest -I ./../googletest/googletest/include -L ./../googletest/build/lib -lgtest


serverTest : $(OBJECTS_SERVER_TEST)

clientTelnetTest : $(OBJECTS_CLIENT_TEST)

serverTest.o : serverTest.cpp

clientTelnetTest.o : clientTelnetTest.cpp

mainTest.o : mainTest.cpp includes/simulatorServer.hpp includes/netClient.hpp myExceptions.hpp

src/simulatorServer.o : includes/simulatorServer.hpp src/simulatorServer.cpp myExceptions.hpp includes/TCPsocketFile.hpp includes/TCPserver.hpp

src/netClient.o : includes/netClient.hpp src/netClient.cpp myExceptions.hpp includes/TCPsocketFile.hpp includes/TCPserver.hpp

src/TCPserver.o : includes/TCPserver.hpp src/TCPserver.cpp includes/TCPsocketFile.hpp

src/TCPsocketFile.o : includes/TCPsocketFile.hpp src/TCPsocketFile.cpp myExceptions.hpp

src/TCPclient.o : includes/TCPclient.hpp src/TCPclient.cpp includes/TCPsocketFile.hpp

# src/TCPqueryIF.o : includes/TCPqueryIF.hpp src/TCPqueryIF.cpp includes/TCPsocketFile.hpp includes/TCPserver.hpp

clean :
	$(RM) $(OBJECTS_SERVER_TEST) $(OBJECTS_CLIENT_TEST) $(MAIN_TEST) mainTest serverTest clientTelnetTest