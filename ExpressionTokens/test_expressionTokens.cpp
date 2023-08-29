#include <iostream>

#include "../lexer/token.hpp"
#include "../lexer/token_enum.hpp"
#include "expressionParser.hpp"
#include "expression.hpp"

int main()
{
    fp::lexer::Token a1(fp::lexer::TokenType::Number, "5", 3, 10);
    fp::lexer::Token a(fp::lexer::TokenType::Add, "+", 5, 10);
    fp::lexer::Token a2(fp::lexer::TokenType::Number, "6", 6, 10);

    std::vector<fp::lexer::Token> myVector;
    myVector.push_back(a1);
    myVector.push_back(a);
    myVector.push_back(a2);

    std::vector<fp::lexer::Token>::const_iterator beginIterator = myVector.cbegin();
    std::vector<fp::lexer::Token>::const_iterator endIterator = myVector.cend();

    fp::Parser::ExpressionParser eParser(beginIterator, endIterator);

    std::shared_ptr<fp::IExpression> expression = eParser.parse();
        
    std::cout << expression->get_value() <<std::flush;
    
    return 0;
}
