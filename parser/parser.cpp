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
        ssize_t estimated_vector_size = std::ceil(((end-1)->row() - it->row())*0.7);
        commands.reserve(estimated_vector_size);

        std::unique_ptr<com::Command> comm;
        while (it != end)
        {
            std::tie(comm, it) = CommandsFactory::create(it, end);
            commands.emplace_back( std::move(comm) );
        }

        if(commands.capacity()*2 > commands.size()*3){
            commands.shrink_to_fit();
        }
    }
    return std::make_unique<com::CodeBlockCommand>(std::move(commands));
}
