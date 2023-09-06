CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Wextra -std=c++17
CXXFLAGS += -g3
CXXFLAGS += -Werror
CXXFLAGS += -I ExpressoinTokens/

OBJECTS = test_expressionTokens.o expressionParser.o  add.o div.o great_operator.o literal.o mull_operator.o small_operator.o sub.o variable_expression.o ../../lexer/token.o ../../lexer/lexer.o

test_expressionTokens: $(OBJECTS)

test_expressionTokens.o: test_expressionTokens.cpp expression.hpp ../../lexer/token.hpp ../../lexer/token_enum.hpp expressionParser.hpp

expressionParser.o: expressionParser.cpp expressionParser.hpp 

../../lexer/token.o: ../../lexer/token.cpp ../../lexer/token.hpp ../../lexer/token_enum.hpp

add.o: add.cpp add.hpp

div.o: div.cpp div.hpp

great_operator.o: great_operator.cpp great_operator.hpp

literal.o: literal.cpp literal.hpp

mull_operator.o: mull_operator.cpp mull_operator.hpp

small_operator.o: small_operator.cpp small_operator.hpp

sub.o: sub.cpp sub.hpp

variable_expression.o: variable_expression.cpp variable_expression.hpp

../../lexer/lexer.o: ../../lexer/lexer.cpp ../../lexer/lexer.hpp


clean:
	$(RM) $(OBJECTS) test_expressionTokens
