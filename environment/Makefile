CXX = g++
CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -g3
CXXFLAGS += -Werror 
CXXFLAGS += -I ./../googletest/googletest/include -L ./../googletest/build/lib -lgtest -lgtest_main -pthread

dataMapTest : dataMapTest.o
	g++   dataMapTest.o   -o dataMapTest -I ./../googletest/googletest/include -L ./../googletest/build/lib -lgtest -lgtest_main -pthread

dataMapTest.o : dataMapTest.cpp dataMap.hpp


# environment.o: environment.hpp  environment.cpp
# simulator.o : simulator.hpp simulator.cpp


clean:
	$(RM) *.o ./dataMapTest