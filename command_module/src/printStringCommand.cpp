#include "../includes/printStringCommand.hpp"

fp::com::PrintStringCommand::PrintStringCommand(std::string const& message)
: m_message(message)
{}

fp::com::PrintStringCommand::PrintStringCommand(std::string && message)
: m_message(message)
{}

fp::PrintStringCommand::PrintStringCommand(std::string const& message)
: m_message(message)
{}

fp::PrintStringCommand::execute()
{
    fp::environment::ostream.printS(m_message);
}
