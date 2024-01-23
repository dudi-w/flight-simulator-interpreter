#include <string>

//parser
#include "parser.hpp"
#include "commands_factory.hpp"
#include "expressionParser.hpp"
#include "parser_exceptions.hpp"

#include "expression.hpp"

//commands
#include "codeBlockCommand.hpp"
#include "whileCommand.hpp"
#include "connectCommand.hpp"
#include "openDataServerCommand.hpp"
#include "sleepCommand.hpp"
#include "assignmentCommand.hpp"
#include "allocationRemoteVarCommand.hpp"
#include "allocationLocalVarCommand.hpp"
#include "printExpCommand.hpp"
#include "printStringCommand.hpp"


using namespace fp;
using namespace parser;

using TokensItr = std::vector<lexer::Token>::const_iterator;
using ComPtr = std::unique_ptr<com::Command>;

std::pair<ComPtr, TokensItr> CommandsFactory::create(TokensItr it, TokensItr end)
{   
    if(it != end){
        if(auto b_it = m_buildersMap.find(it->type()); b_it != m_buildersMap.end()){
            return b_it->second(it, end);
        } else {
            throw ParserError(it->row(), it->column(), "unexpected token \"" + it->str() + "\".");
        }
    }
    throw ParserError(it->row(), it->column(), "unexpected end of file.");
}

std::pair<std::unique_ptr<exp::Expression>, TokensItr> fp::parser::CommandsFactory::build_expression(TokensItr it, TokensItr end)
{
    return ExpressionParser(it, end).parse();
}

std::pair<ComPtr, TokensItr> CommandsFactory::curlyBracket_heandler(TokensItr it, TokensItr end)
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
        return {std::make_unique<com::ConnectCommand>(host, port), it + 3};
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
        } else if(auto [expr, it_behind_expr] = build_expression(it + 1, end); expr){
            return {std::make_unique<com::PrintExpCommand>(std::move(expr)), it_behind_expr};

        }
    }
    throw ParserError(it->row(), it->column(), "print expects to get string or expression.");
}

std::pair<ComPtr, TokensItr> CommandsFactory::sleep_builder(TokensItr it, TokensItr end)
{
    if(it + 1 < end){
        if(auto [expr, it_behind_expr] = build_expression(it + 1, end); expr){
            ComPtr sleep_comm = std::make_unique<com::SleepCommand>(std::move(expr));
            return {std::move(sleep_comm), it_behind_expr};
        }
    }
    throw ParserError(it->row(), it->column(), "sleep expects to get an expression.");
}

std::pair<ComPtr, TokensItr> CommandsFactory::var_heandler(TokensItr it, TokensItr end)
{
    if(it + 1 >= end || (it + 1)->type() != lexer::TokenType::Name ){
        throw ParserError(it->row(), it->column(), "behind \"var\" is expected to be \"VarName\".");
    }

    std::string const& varName = (it + 1)->str();
    if(it + 4 < end
        && (it + 2)->type() == lexer::TokenType::Assign
        && (it + 3)->type() == lexer::TokenType::Bind
        && (it + 4)->type() == lexer::TokenType::String
    ) {
        std::string const& path = (it + 4)->str();
        return {std::make_unique<com::AllocationRemoteVarCommand>(varName, path), it + 5};
    }
    bool no_init = it + 2 == end || (it + 2)->type() != lexer::TokenType::Assign;
    return {std::make_unique<com::AllocationLocalVarCommand>(varName), it + 1 + no_init};
}

std::pair<ComPtr, TokensItr> fp::parser::CommandsFactory::assignment_builder(TokensItr it, TokensItr end)
{
    if(it + 2 < end && (it + 1)->type() == lexer::TokenType::Assign){
        std::string const& varName = it->str();
        if(auto [expr, it_behind_expr] = build_expression(it + 2, end); expr){
            return {std::make_unique<com::AssigmentCommand>(varName, std::move(expr)), it_behind_expr}; 
        }
    }
    throw ParserError(it->row(), it->column(), "var assignment expects to get an expression.");
}

std::pair<ComPtr, TokensItr> CommandsFactory::while_builder(TokensItr it, TokensItr end)
{
    if(auto [expr, it_behind_expr] = build_expression(it + 1, end); expr){
        auto [comm, it_behind_com] = CommandsFactory::create(it_behind_expr, end);
        ComPtr while_com = std::make_unique<com::WhileCommand>(std::move(expr), std::move(comm));
        return std::make_pair(std::move(while_com), it_behind_com);
    }
    throw ParserError(it->row(), it->column(), "whileCommand expects to get an expression end command.");
}
