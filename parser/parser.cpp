#include <memory>
#include <string>

#include "parser.hpp"

#include "../command_module/includes/codeBlockCommand.hpp"
#include "../command_module/includes/whileCommand.hpp"
#include "../command_module/includes/connectCommand.hpp"
#include "../command_module/includes/sleepCommand.hpp"
#include "../command_module/includes/assignmentCommand.hpp"
#include "../command_module/includes/bindCommand.hpp"
#include "../command_module/includes/printExpCommand.hpp"
#include "../command_module/includes/printStringCommand.hpp"

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

std::unique_ptr<Expression> fp::parser::Parser::build_expression(TokensItr &it, TokensItr end)
{
    return std::unique_ptr<Expression>();
}

std::unique_ptr<Command> Parser::codeBlock_builder(TokensItr &it, TokensItr end)
{
    TokensItr beginOfBlock = ++it;
    int nesting_level = 0;
    while (it != end && nesting_level >= 0)
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

std::unique_ptr<Command> fp::parser::Parser::connect_builder(TokensItr &it, TokensItr end)
{
    if(end - it >= 3 
        && it->type() == lexer::TokenType::Connect 
        && (it + 1)->type() == lexer::TokenType::String 
        && (it + 2)->type() == lexer::TokenType::Number
    ){
        std::string host = (it + 1)->str();
        std::string port = (it + 2)->str();
        it += 3;
        return std::make_unique<com::ConnectCommand>(host, port);
    } else {
        throw; //TODO: put hare relevant exception.
    }
}

std::unique_ptr<Command> fp::parser::Parser::openDataServer_builder(TokensItr &it, TokensItr end)
{
    if(end - it >= 3 
        && it->type() == lexer::TokenType::OpenDataServer 
        && (it + 1)->type() == lexer::TokenType::Number 
        && (it + 2)->type() == lexer::TokenType::Number
    ){
        std::string const& port = (it + 1)->str();
        std::string const& ups = (it + 2)->str();
        it += 3;
        return std::make_unique<com::ConnectCommand>(port, ups);
    } else {
        throw; //TODO: put hare relevant exception.
    }
}

std::unique_ptr<Command> fp::parser::Parser::print_builder(TokensItr &it, TokensItr end)
{
    if(end - it >= 2 && it->type() == lexer::TokenType::Print){
        if((it + 1)->type() == lexer::TokenType::String){
            std::string const& msg = (it + 1)->str();
            it += 2;
            return std::make_unique<com::PrintStringCommand>(msg);
        } else if(auto expr = build_expression(++it, end); expr){
            return std::make_unique<com::PrintExpCommand>(expr);
        }
    } 
    throw; //TODO: put hare relevant exception.
}

std::unique_ptr<Command> fp::parser::Parser::sleep_builder(TokensItr &it, TokensItr end)
{
    return std::unique_ptr<Command>();
}

std::unique_ptr<Command> fp::parser::Parser::var_heandler(TokensItr &it, TokensItr end)
{
    if(end - it >= 3 
        && it->type() == lexer::TokenType::Var 
        && (it + 1)->type() == lexer::TokenType::Name 
        && (it + 2)->type() == lexer::TokenType::Equal
    ){
        std::string const& varName = (it + 1)->str();
        if(end - it >= 5
            && (it + 3)->type() == lexer::TokenType::Bind
            && (it + 4)->type() == lexer::TokenType::String
        ) {
            std::string const& path = (it + 1)->str();
            it += 5;
            return std::make_unique<com::BindCommand>(varName, path);
        }
        it += 3;
        if(auto expr = build_expression(it, end); expr){
            return std::make_unique<com::AssigmentCommand>(varName, expr); //??????
        }
    }
    throw; //TODO: put hare relevant exception.
}

std::unique_ptr<Command> fp::parser::Parser::while_builder(TokensItr &it, TokensItr end)
{
    return std::unique_ptr<Command>();
}
