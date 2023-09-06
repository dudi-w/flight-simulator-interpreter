CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Wextra -std=c++17
CXXFLAGS += -g3
CXXFLAGS += -Werror
CXXFLAGS += -I ExpressoinTokens/

OBJECTS = test_expressionTokens.o expressionParser.o  ../../expression/add.o ../../expression/div.o ../../expression/great_operator.o ../../expression/literal.o ../../expression/mul.o ../../expression/small_operator.o ../../expression/sub.o ../../expression/variable_expression.o ../../lexer/token.o ../../lexer/lexer.o

test_expressionTokens: $(OBJECTS)

test_expressionTokens.o: test_expressionTokens.cpp ../../expression/expression.hpp ../../lexer/token.hpp ../../lexer/token_enum.hpp expressionParser.hpp

expressionParser.o: expressionParser.cpp expressionParser.hpp 

../../lexer/token.o: ../../lexer/token.cpp ../../lexer/token.hpp ../../lexer/token_enum.hpp

../../expression/add.o: ../../expression/add.cpp ../../expression/add.hpp

../../expression/div.o: ../../expression/div.cpp ../../expression/div.hpp

../../expression/great_operator.o: ../../expression/great_operator.cpp ../../expression/great_operator.hpp

../../expression/literal.o: ../../expression/literal.cpp ../../expression/literal.hpp

../../expression/mul.o: ../../expression/mul.cpp ../../expression/mul.hpp

../../expression/small_operator.o: ../../expression/small_operator.cpp ../../expression/small_operator.hpp

../../expression/sub.o: ../../expression/sub.cpp ../../expression/sub.hpp

../../expression/variable_expression.o: ../../expression/variable_expression.cpp ../../expression/variable_expression.hpp

../../lexer/lexer.o: ../../lexer/lexer.cpp ../../lexer/lexer.hpp

clean:
	$(RM) $(OBJECTS) test_expressionTokens
