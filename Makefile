CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Wextra -std=c++17
CXXFLAGS += -g3
CXXFLAGS += -Werror
CXXFLAGS += -I lexer/

lexer/lexer_test: lexer/lexer_test.o lexer/lexer.o lexer/token.o

lexer/lexer_test.o: lexer/lexer_test.cpp

lexer/token.o: lexer/token.cpp lexer/token.hpp

lexer/lexer.o: lexer/lexer.cpp lexer/lexer.hpp lexer/I_lexer.hpp lexer/lexer_exceptions.hpp

clean:
	$(RM) lexer/*.o *.o lexer/lexer_test