#include "printStringCommand.hpp"
#include "environment.hpp"

fp::com::PrintStringCommand::PrintStringCommand(std::string const& message)
: m_message(message)
{}

fp::com::PrintStringCommand::PrintStringCommand(std::string && message)
: m_message(message)
{}

fp::PrintStringCommand::execute()
{
    fp::env::Environment::print_str(m_message);
}
