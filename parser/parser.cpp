#include <memory>
#include <string>

#include "../includs/command.hpp"
#include "../command_module/includes/codeBlockCommand.hpp"
#include "parser.hpp"
#include "commands_factory.hpp"

using namespace fp;
using namespace parser;

std::unique_ptr<Command> Parser::parse(std::vector<lexer::Token> const& tokens)
{
    return parse(tokens.cend(), tokens.cend());
}

std::unique_ptr<Command> Parser::parse(TokensItr it, TokensItr end)
{
    std::vector<std::unique_ptr<Command>> commands;
    while (it != end)
    {
        auto [comm, next_it] = CommandsFactory::create(it, end);
        it = next_it;
        commands.emplace_back( std::move(comm) );
    }
    return std::make_unique<com::CodeBlockCommand>(commands);
}
