CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Wextra -std=c++17
CXXFLAGS += -g3
# CXXFLAGS += -Werror
CXXFLAGS += -I include/
CXXFLAGS += -I lexer/

main: main.o lexer/lexer.o lexer/token.o

main.o: main.cpp

lexer/token.o: lexer/token.cpp lexer/token.hpp

lexer/lexer.o: lexer/lexer.cpp lexer/lexer.hpp

clean:
	$(RM) lexer/*.o *.o main