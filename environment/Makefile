CXX = g++
CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -g3
CXXFLAGS += -Werror 
CXXFLAGS += -I ./../communication_mudule/includes 
CXXFLAGS += -I ./../googletest/googletest/include -L ./../googletest/build/lib -lgtest -lgtest_main -pthread

COMMUN = ../communication_mudule/
VAR = ../variable/

SIMULATOR_TEST = simulatorTest.o simulator.o $(COMMUN)src/simulatorServer.o $(COMMUN)src/TCPserver.o $(COMMUN)src/netClient.o $(COMMUN)src/TCPsocketFile.o $(COMMUN)src/TCPclient.o

ENVIRONMENT_TEST = environmentTest.o environment.o simulator.o $(COMMUN)src/simulatorServer.o $(COMMUN)src/TCPserver.o $(COMMUN)src/netClient.o $(COMMUN)src/TCPsocketFile.o $(COMMUN)src/TCPclient.o $(VAR)local_variable.o $(VAR)remote_variable.o $(VAR)variable_map.o

dataMapTest : dataMapTest.o
	g++   dataMapTest.o   -o dataMapTest -I ./../googletest/googletest/include -L ./../googletest/build/lib -lgtest -lgtest_main -pthread

dataMapTest.o : dataMapTest.cpp dataMap.hpp



simulatorTest : $(SIMULATOR_TEST)

simulatorTest.o : simulatorTest.cpp simulator.hpp

simulator.o : simulator.hpp simulator.cpp $(COMMUN)includes/simulatorServer.hpp $(COMMUN)includes/netClient.hpp $(COMMUN)myExceptions.hpp

$(COMMUN)src/simulatorServer.o : $(COMMUN)includes/simulatorServer.hpp $(COMMUN)src/simulatorServer.cpp $(COMMUN)myExceptions.hpp $(COMMUN)includes/TCPsocketFile.hpp $(COMMUN)includes/TCPserver.hpp
$(COMMUN)src/TCPserver.o : $(COMMUN)includes/TCPserver.hpp $(COMMUN)src/TCPserver.cpp $(COMMUN)includes/TCPsocketFile.hpp
$(COMMUN)src/netClient.o : $(COMMUN)includes/netClient.hpp $(COMMUN)src/netClient.cpp $(COMMUN)myExceptions.hpp $(COMMUN)includes/TCPsocketFile.hpp $(COMMUN)includes/TCPserver.hpp
$(COMMUN)src/TCPclient.o : $(COMMUN)includes/TCPclient.hpp $(COMMUN)src/TCPclient.cpp $(COMMUN)includes/TCPsocketFile.hpp
$(COMMUN)src/TCPsocketFile.o : $(COMMUN)includes/TCPsocketFile.hpp $(COMMUN)src/TCPsocketFile.cpp $(COMMUN)myExceptions.hpp

environmentTest : $(ENVIRONMENT_TEST)

environmentTest.o  : environmentTest.cpp $(VAR)remote_variable.hpp $(VAR)local_variable.hpp environment.hpp

environment.o : environment.cpp environment.hpp dataMap.hpp

$(VAR)local_variable.o : $(VAR)local_variable.cpp $(VAR)local_variable.hpp $(VAR)variable.hpp
$(VAR)remote_variable.o : $(VAR)remote_variable.cpp $(VAR)remote_variable.hpp $(VAR)variable.hpp
$(VAR)variable_map.o : $(VAR)variable_map.cpp $(VAR)variable_map.hpp $(VAR)variable.hpp $(VAR)local_variable.hpp $(VAR)remote_variable.hpp

clean:
	$(RM) *.o ./dataMapTest $(SIMULATOR_TEST) $(ENVIRONMENT_TEST)