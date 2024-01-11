#include "codeBlockCommand.hpp"


fp::com::CodeBlockCommand::CodeBlockCommand(fp::Commands && commands)
: m_commands(std::move(commands))
{}

void fp::com::CodeBlockCommand::execute()
{
    for(auto & command : m_commands){
        command->execute();
    }
}
