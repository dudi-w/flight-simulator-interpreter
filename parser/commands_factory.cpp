#include "commands_factory.hpp"
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

using TokensItr = std::vector<lexer::Token>::const_iterator;
using ComPtr = std::unique_ptr<Command>;

std::pair<ComPtr, TokensItr> CommandsFactory::create(TokensItr it, TokensItr end)
{
    if(auto b_it = m_buildersMap.find(it->type()); b_it != m_buildersMap.end()){
        return b_it->second(it, end);
    } else {
        throw; //TODO: put hare relevant exception.
    }
}

std::unique_ptr<Expression> fp::parser::CommandsFactory::build_expression(TokensItr &it, TokensItr end)
{
    return std::unique_ptr<Expression>();
}

std::pair<ComPtr, TokensItr> CommandsFactory::codeBlock_builder(TokensItr it, TokensItr end)
{   
    if(it->type() == lexer::TokenType::LeftCurlyBracket){
        TokensItr beginOfBlock = ++it;
        int nesting_level = 0;
        while (it != end && nesting_level >= 0)
        {
            if(!nesting_level && it->type() == lexer::TokenType::RightCurlyBracket){
                ++it;
                return {Parser::parse(beginOfBlock, it), it};
            }
            nesting_level += (it->type() == lexer::TokenType::LeftCurlyBracket);
            nesting_level -= (it->type() == lexer::TokenType::RightCurlyBracket);
            ++it;
        }
    }
    throw; //TODO: put hare relevant exception.
}

std::pair<ComPtr, TokensItr> CommandsFactory::connect_builder(TokensItr it, TokensItr end)
{
    if(end - it >= 3 
        && it->type() == lexer::TokenType::Connect 
        && (it + 1)->type() == lexer::TokenType::String 
        && (it + 2)->type() == lexer::TokenType::Number
    ){
        std::string const& host = (it + 1)->str();
        std::string const& port = (it + 2)->str();
        it += 3;
        return {std::make_unique<com::ConnectCommand>(host, port), it};
    } else {
        throw; //TODO: put hare relevant exception.
    }
}

std::pair<ComPtr, TokensItr> CommandsFactory::openDataServer_builder(TokensItr it, TokensItr end)
{
    if(end - it >= 3
        && it->type() == lexer::TokenType::OpenDataServer 
        && (it + 1)->type() == lexer::TokenType::Number 
        && (it + 2)->type() == lexer::TokenType::Number
    ){
        std::string const& port = (it + 1)->str();
        std::string const& ups = (it + 2)->str();
        it += 3;
        return {std::make_unique<com::ConnectCommand>(port, ups), it};
    } else {
        throw; //TODO: put hare relevant exception.
    }
}

std::pair<ComPtr, TokensItr> CommandsFactory::print_builder(TokensItr it, TokensItr end)
{
    if(end - it >= 2 && it->type() == lexer::TokenType::Print){
        if((it + 1)->type() == lexer::TokenType::String){
            std::string const& msg = (it + 1)->str();
            it += 2;
            return {std::make_unique<com::PrintStringCommand>(msg), it};
        } else if(auto expr = build_expression(++it, end); expr){
            return {std::make_unique<com::PrintExpCommand>(expr), it};
        }
    } 
    throw; //TODO: put hare relevant exception.
}

std::pair<ComPtr, TokensItr> CommandsFactory::sleep_builder(TokensItr it, TokensItr end)
{
    if(it->type() == lexer::TokenType::Sleep){
        ++it;
        if(auto expr = build_expression(it, end); expr){
            auto sleep_comm = std::make_unique<com::SleepCommand>(std::move(expr));
            return {std::move(sleep_comm), it};
        } 
    }
    throw; //TODO: put hare relevant exception.
}

std::pair<ComPtr, TokensItr> CommandsFactory::var_heandler(TokensItr it, TokensItr end)
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
            return {std::make_unique<com::BindCommand>(varName, path), it};
        }
        it += 3;
        if(auto expr = build_expression(it, end); expr){
            return {std::make_unique<com::AssigmentCommand>(varName, expr), it}; //??????
        }
    }
    throw; //TODO: put hare relevant exception.
}

std::pair<ComPtr, TokensItr> CommandsFactory::while_builder(TokensItr it, TokensItr end)
{
    if(it->type() == lexer::TokenType::While){
        ++it;
        if(auto expr = build_expression(it, end); expr){
            auto [comm, next_it] = CommandsFactory::create(it, end);
            ComPtr while_comm = std::make_unique<com::WhileCommand>(std::move(expr), std::move(comm));
            return std::make_pair(while_comm, next_it);
        }
    }
    throw; //TODO: put hare relevant exception.
}
