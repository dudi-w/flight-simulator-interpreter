#include <iostream>

#include "../lexer/token.hpp"
#include "../lexer/token_enum.hpp"
#include "expressionParser.hpp"
#include "expression.hpp"

int main()
{
    fp::lexer::Token a0(fp::lexer::TokenType::LeftBracket, "(", 3, 10);
    fp::lexer::Token a1(fp::lexer::TokenType::Add, "+", 3, 10);
    fp::lexer::Token a2(fp::lexer::TokenType::Number, "10", 3, 10);
    fp::lexer::Token a3(fp::lexer::TokenType::Add, "+", 3, 10);
    fp::lexer::Token a4(fp::lexer::TokenType::Number, "5", 3, 10);
    fp::lexer::Token a5(fp::lexer::TokenType::RightBracket, ")", 3, 10);
    fp::lexer::Token a6(fp::lexer::TokenType::LeftCurlyBracket, "{", 3, 10);
    fp::lexer::Token a7(fp::lexer::TokenType::Mul, "*", 3, 10);
    fp::lexer::Token a8(fp::lexer::TokenType::Number, "5", 3, 10);

    std::vector<fp::lexer::Token> myVector;
    fp::lexer::Token myTokens[] = { a0, a2, a3, a4, a5, a6, a7, a8};

    for (const auto& token : myTokens) {
        myVector.push_back(token);
    }

    std::vector<fp::lexer::Token>::const_iterator beginIterator = myVector.cbegin();
    std::vector<fp::lexer::Token>::const_iterator endIterator = myVector.cend();

    fp::parser::ExpressionParser eParser(beginIterator, endIterator);

    std::shared_ptr<fp::IExpression> expression = eParser.parse();
    
    std::cout << expression->get_value() << std::endl;
    
    return 0;
}
