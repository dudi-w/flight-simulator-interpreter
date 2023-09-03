CXX = g++

CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -g3

CPPFLAGS = -I ./includes -I ./../

# LDLIBS += -lcurlpp -lcurl -lgumbo

OBJECTS_SERVER_TEST = serverTest.o src/netServer.o src/TCPsocketFile.o src/TCPserver.o
OBJECTS_CLIENT_TEST = clientTest.o src/netClient.o src/TCPsocketFile.o src/TCPclient.o

all: serverTest clientTest

serverTest : $(OBJECTS_SERVER_TEST)

clientTest : $(OBJECTS_CLIENT_TEST)

serverTest.o : serverTest.cpp

clientTest.o : clientTest.cpp

src/netServer.o : includes/netServer.hpp src/netServer.cpp myExceptions.hpp includes/TCPsocketFile.hpp includes/TCPserver.hpp

src/netClient.o : includes/netClient.hpp src/netClient.cpp myExceptions.hpp includes/TCPsocketFile.hpp includes/TCPserver.hpp

src/TCPserver.o : includes/TCPserver.hpp src/TCPserver.cpp includes/TCPsocketFile.hpp

src/TCPsocketFile.o : includes/TCPsocketFile.hpp src/TCPsocketFile.cpp myExceptions.hpp

src/TCPclient.o : includes/TCPclient.hpp src/TCPclient.cpp includes/TCPsocketFile.hpp

# src/TCPqueryIF.o : includes/TCPqueryIF.hpp src/TCPqueryIF.cpp includes/TCPsocketFile.hpp includes/TCPserver.hpp

clean :
	$(RM) $(OBJECTS_SERVER_TEST) $(OBJECTS_CLIENT_TEST)