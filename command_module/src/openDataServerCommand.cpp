#include "openDataServerCommand.hpp"
#include "environment.hpp"

fp::com::OpenServerCommand::OpenServerCommand(std::string const& port, std::string const& ups)
: m_port(port)
, m_ups(ups)
{}

fp::com::OpenServerCommand::OpenServerCommand(std::string && port, std::string && ups)
: m_port(std::move(port))
, m_ups(std::move(ups))
{}

void fp::com::OpenServerCommand::execute()
{
    fp::env::Environment::simulatorControl().set_server_port(static_cast<uint16_t>(stoi(m_port)));
    fp::env::Environment::simulatorControl().set_server_update_per_second(static_cast<uint16_t>(stoi(m_ups)));
}
