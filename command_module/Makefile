CXX = g++

CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -g3

CPPFLAGS = -I ./includes -I ./../environment

# LDLIBS += -lcurlpp -lcurl -lgumbo

OBJECTS = src/whileCommand.o src/allocationLocalVarCommand.o src/allocationRemoteVarCommand.o src/assignmentCommand.o src/codeBlockCommand.o src/connectCommand.o src/openDataServerCommand.o src/printExpCommand.o src/printStringCommand.o src/sleepCommand.o 

mainTest : $(OBJECTS)


src/whileCommand.o : src/whileCommand.cpp includes/src/whileCommand.hpp ../command.hpp 
src/allocationLocalVarCommand.o : src/allocationLocalVarCommand.cpp includes/src/allocationLocalVarCommand.hpp ../command.hpp 
src/allocationRemoteVarCommand.o : src/allocationRemoteVarCommand.cpp includes/src/allocationRemoteVarCommand.hpp ../command.hpp 
src/assignmentCommand.o : src/assignmentCommand.cpp includes/src/assignmentCommand.hpp ../command.hpp 
src/codeBlockCommand.o : src/codeBlockCommand.cpp includes/src/codeBlockCommand.hpp ../command.hpp 
src/connectCommand.o : src/connectCommand.cpp includes/src/connectCommand.hpp ../command.hpp 
src/openDataServerCommand.o : src/openDataServerCommand.cpp includes/src/openDataServerCommand.hpp ../command.hpp 
src/printExpCommand.o : src/printExpCommand.cpp includes/src/printExpCommand.hpp ../command.hpp 
src/printStringCommand.o : src/printStringCommand.cpp includes/src/printStringCommand.hpp ../command.hpp 
src/sleepCommand.o : src/sleepCommand.cpp includes/src/sleepCommand.hpp ../command.hpp 

clean :
	$(RM) $(OBJECTS)