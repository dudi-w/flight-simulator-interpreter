CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Wextra -std=c++17
CXXFLAGS += -g3
CXXFLAGS += -Werror
CXXFLAGS += -I lexer/

lexer_test: lexer_test.o lexer.o token.o

lexer_test.o: lexer_test.cpp

token.o: token.cpp token.hpp

lexer.o: lexer.cpp lexer.hpp I_lexer.hpp lexer_exceptions.hpp

clean:
	$(RM) *.o *.o lexer_test