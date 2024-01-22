#include <memory>
#include <string>
#include <cmath>

#include "command.hpp"
#include "codeBlockCommand.hpp"
#include "parser.hpp"
#include "commands_factory.hpp"

using namespace fp;
using namespace parser;

std::unique_ptr<com::Command> Parser::parse(std::vector<lexer::Token> const& tokens)
{
    return parse(tokens.cbegin(), tokens.cend());
}

std::unique_ptr<com::Command> Parser::parse(TokensItr it, TokensItr end)
{
    std::vector<std::unique_ptr<com::Command>> commands;
    if(it < end){
        std::unique_ptr<com::Command> comm;
        while (it != end)
        {
            std::tie(comm, it) = CommandsFactory::create(it, end);
            commands.emplace_back( std::move(comm) );
        }
    }
    return std::make_unique<com::CodeBlockCommand>(std::move(commands));
}
