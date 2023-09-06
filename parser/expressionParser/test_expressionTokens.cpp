#include <iostream>

#include "../../lexer/token.hpp"
#include "../../lexer/token_enum.hpp"
#include "expressionParser.hpp"
#include "../../expression/expression.hpp"
#include "../../lexer/lexer.hpp"

int main(int argc, char** argv)
{

	fp::lexer::Lexer lexer;

    std::vector<fp::lexer::Token> myVector = lexer.tokenize(
		    argc == 2 ? argv[1] : "1 -1 < 2 + 1 "
		    );


    std::vector<fp::lexer::Token>::const_iterator beginIterator = myVector.cbegin();
    std::vector<fp::lexer::Token>::const_iterator endIterator = myVector.cend();

    fp::parser::ExpressionParser eParser(beginIterator, endIterator);

    std::unique_ptr<fp::exp::IExpression> expression = eParser.parse().first;
    
    std::cout << expression->get_value() << std::endl;
    
    return 0;
}