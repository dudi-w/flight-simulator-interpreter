#include "parser.hpp"

using namespace fp;
using namespace parser;



std::unique_ptr<Command> Parser::parse(std::vector<lexer::Token> const &tokens) const
{
    auto it = tokens.cbegin();
    return parse(it, tokens.cend());
}

std::unique_ptr<Command> Parser::parse(TokensItr &, TokensItr)
{
    return std::unique_ptr<Command>();
}

std::unique_ptr<Command> Parser::codeBlock_builder(TokensItr &it, TokensItr end)
{
    TokensItr beginOfBlock = ++it;
    size_t nesting_level = 0;
    while (it != end)
    {
        if(!nesting_level && it->type() == lexer::TokenType::RightCurlyBracket){
            return parse(beginOfBlock, it++);
        }
        nesting_level += (it->type() == lexer::TokenType::LeftCurlyBracket);
        nesting_level -= (it->type() == lexer::TokenType::RightCurlyBracket);
        ++it;
    }
    throw; //TODO: put hare relevant exception.
}
