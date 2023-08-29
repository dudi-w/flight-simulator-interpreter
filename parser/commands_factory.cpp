#include "commands_factory.hpp"
#include "parser.hpp"
#include "parser_exceptions.hpp"

#include "../command_module/includes/codeBlockCommand.hpp"
#include "../command_module/includes/whileCommand.hpp"
#include "../command_module/includes/connectCommand.hpp"
#include "../command_module/includes/openDataServerCommand.hpp"
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
    if(it != end){
        if(auto b_it = m_buildersMap.find(it->type()); b_it != m_buildersMap.end()){
            return b_it->second(it, end);
        } else {
            throw ParserError(it->row(), it->column(), "unexpected token \"" + it->str() + "\".");
        }
    }
}

std::pair<std::unique_ptr<Expression> TokensItr> fp::parser::CommandsFactory::build_expression(TokensItr it, TokensItr end)
{
    return {std::unique_ptr<Expression>(), it};
}

std::pair<ComPtr, TokensItr> CommandsFactory::codeBlock_builder(TokensItr it, TokensItr end)
{   
    TokensItr beginOfBlock = ++it;
    int nesting_level = 0;
    while (it != end && nesting_level >= 0)
    {
        if(!nesting_level && it->type() == lexer::TokenType::RightCurlyBracket){
            return {Parser::parse(beginOfBlock, it), it+1};
        }
        nesting_level += (it->type() == lexer::TokenType::LeftCurlyBracket);
        nesting_level -= (it->type() == lexer::TokenType::RightCurlyBracket);
        ++it;
    }
    --beginOfBlock; // the "{"
    throw ParserError(beginOfBlock->row(), beginOfBlock->column(), "No matching closing bracket found.");
}

std::pair<ComPtr, TokensItr> CommandsFactory::connect_builder(TokensItr it, TokensItr end)
{
    if(it + 2 < end 
        && (it + 1)->type() == lexer::TokenType::String 
        && (it + 2)->type() == lexer::TokenType::Number
    ){
        std::string const& host = (it + 1)->str();
        std::string const& port = (it + 2)->str();
        return {std::make_unique<com::ConnectCommand>(host, port), it};
    } else {
        throw ParserError(it->row(), it->column(), "ConnectCommand expects to get a string and a number.");
    }
}

std::pair<ComPtr, TokensItr> CommandsFactory::openDataServer_builder(TokensItr it, TokensItr end)
{
    if(it + 2 < end
        && (it + 1)->type() == lexer::TokenType::Number 
        && (it + 2)->type() == lexer::TokenType::Number
    ){
        std::string const& port = (it + 1)->str();
        std::string const& ups = (it + 2)->str();
        return {std::make_unique<com::OpenServerCommand>(port, ups), it + 3};
    } else {
        throw ParserError(it->row(), it->column(), "OpenServerCommand expects to get two numbers.");
    }
}

std::pair<ComPtr, TokensItr> CommandsFactory::print_builder(TokensItr it, TokensItr end)
{
    if(it + 1 < end){
        if((it + 1)->type() == lexer::TokenType::String){
            std::string const& msg = (it + 1)->str();
            return {std::make_unique<com::PrintStringCommand>(msg), it + 2};
        } else if(auto [expr, next_it] = build_expression(it + 1, end); expr){
            return {std::make_unique<com::PrintExpCommand>(expr), next_it};
        }
    }
    throw ParserError(it->row(), it->column(), "print expects to get string or expression.");
}

std::pair<ComPtr, TokensItr> CommandsFactory::sleep_builder(TokensItr it, TokensItr end)
{
    if(it + 1 < end){
        if(auto [expr, next_it] = build_expression(it + 1, end); expr){
            auto sleep_comm = std::make_unique<com::SleepCommand>(std::move(expr));
            return {std::move(sleep_comm), next_it};
        }
    }
    throw ParserError(it->row(), it->column(), "sleep expects to get an expression.");
}

std::pair<ComPtr, TokensItr> CommandsFactory::var_heandler(TokensItr it, TokensItr end)
{
    if(it + 3 < end
        && (it + 1)->type() == lexer::TokenType::Name 
        && (it + 2)->type() == lexer::TokenType::Equal
    ){
        std::string const& varName = (it + 1)->str();
        if(it + 4 < end
            && (it + 3)->type() == lexer::TokenType::Bind
            && (it + 4)->type() == lexer::TokenType::String
        ) {
            std::string const& path = (it + 1)->str();
            return {std::make_unique<com::BindCommand>(varName, path), it + 5};
        }
        if(auto [expr, next_it] = build_expression(it + 3, end); expr){
            return {std::make_unique<com::AssigmentCommand>(varName, expr), next_it}; //??????
        } else {
            throw ParserError(it->row(), it->column(), "local var expects to get an expression.");
        }
    }
    throw ParserError(it->row(), it->column(), "After \"var\" is expected to be \"VarName\" and \"=\"");
}

std::pair<ComPtr, TokensItr> CommandsFactory::while_builder(TokensItr it, TokensItr end)
{
    if(auto [expr, next_it_1] = build_expression(it + 1, end); expr){
        auto [comm, next_it_2] = CommandsFactory::create(next_it_1, end);
        ComPtr while_comm = std::make_unique<com::WhileCommand>(std::move(expr), std::move(comm));
        return {while_comm, next_it_2};
    }
    throw ParserError(it->row(), it->column(), "whileCommand expects to get an expression end command.");
}
