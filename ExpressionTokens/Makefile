CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Wextra -std=c++17
CXXFLAGS += -g3
CXXFLAGS += -Werror
CXXFLAGS += -I ExpressoinTokens/

test_expressionTokens: test_expressionTokens.o expressionParser.o ../lexer/token.o ../lexer/token_enum.o expression.o

test_expressionTokens.o: test_expressionTokens.cpp

expressionParser.o: expressionParser.cpp expressionParser.hpp 

../lexer/token.o: ../lexer/token.cpp ../lexer/token.hpp

../lexer/token_enum.o: ../lexer/token_enum.hpp

expression.o: expression.hpp


clean:
	$(RM) *.o *.o test_expressionTokens