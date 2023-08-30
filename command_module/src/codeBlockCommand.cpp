#include "../includes/codeBlockCommand.hpp"

fp::CodeBlockCommand::CodeBlockCommand(std::vector<fp::Command> const& commands)
: m_commands(commands)
{}

void fp::CodeBlockCommand::execute()
{
    for(auto & command : m_commands){
        command.execute();
    }
}
