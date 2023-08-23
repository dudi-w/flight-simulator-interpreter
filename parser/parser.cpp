#include "parser.hpp"

using namespace fp;
using namespace parser;



std::unique_ptr<Command> Parser::parse(std::vector<lexer::Token> const &tokens) const
{
    auto it = tokens.cbegin();
    return parse(it, tokens.cend());
}

std::unique_ptr<Command> Parser::parse(TokensItr& it, TokensItr end)
{
    std::vector<std::unique_ptr<Command>> commands;
    while (it != end)
    {
        if(auto b_it = m_buildersMap.find(it->type()); b_it != m_buildersMap.end()){
            commands.emplace_back( b_it->second(it, end) );
        } else {
            throw; //TODO: put hare relevant exception.
        }
    }
    return std::make_unique<com::CodeBlockCommand>(commands);
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
