CXX = g++
CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -g3
CXXFLAGS += -Werror 
CXXFLAGS += -I ./../communication_mudule/includes 
CXXFLAGS += -I ./../googletest/googletest/include -L ./../googletest/build/lib -lgtest -lgtest_main -pthread

COMMUN = ../communication_mudule/

MAIN_TEST = mainTest.o simulator.o $(COMMUN)src/simulatorServer.o $(COMMUN)src/TCPserver.o $(COMMUN)src/netClient.o $(COMMUN)src/TCPsocketFile.o $(COMMUN)src/TCPclient.o

dataMapTest : dataMapTest.o
	g++   dataMapTest.o   -o dataMapTest -I ./../googletest/googletest/include -L ./../googletest/build/lib -lgtest -lgtest_main -pthread

dataMapTest.o : dataMapTest.cpp dataMap.hpp


# environment.o: environment.hpp  environment.cpp
mainTest : $(MAIN_TEST)

mainTest.o : mainTest.cpp simulator.hpp

simulator.o : simulator.hpp simulator.cpp $(COMMUN)includes/simulatorServer.hpp $(COMMUN)includes/netClient.hpp $(COMMUN)myExceptions.hpp

$(COMMUN)src/simulatorServer.o : $(COMMUN)includes/simulatorServer.hpp $(COMMUN)src/simulatorServer.cpp $(COMMUN)myExceptions.hpp $(COMMUN)includes/TCPsocketFile.hpp $(COMMUN)includes/TCPserver.hpp
$(COMMUN)src/TCPserver.o : $(COMMUN)includes/TCPserver.hpp $(COMMUN)src/TCPserver.cpp $(COMMUN)includes/TCPsocketFile.hpp
$(COMMUN)src/netClient.o : $(COMMUN)includes/netClient.hpp $(COMMUN)src/netClient.cpp $(COMMUN)myExceptions.hpp $(COMMUN)includes/TCPsocketFile.hpp $(COMMUN)includes/TCPserver.hpp
$(COMMUN)src/TCPclient.o : $(COMMUN)includes/TCPclient.hpp $(COMMUN)src/TCPclient.cpp $(COMMUN)includes/TCPsocketFile.hpp
$(COMMUN)src/TCPsocketFile.o : $(COMMUN)includes/TCPsocketFile.hpp $(COMMUN)src/TCPsocketFile.cpp $(COMMUN)myExceptions.hpp



clean:
	$(RM) *.o ./dataMapTest