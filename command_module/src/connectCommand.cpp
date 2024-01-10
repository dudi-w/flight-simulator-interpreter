#include "connectCommand.hpp"
#include "environment.hpp"

fp::com::ConnectCommand::ConnectCommand(std::string const& host ,std::string const& port)
: m_host(host)
, m_port(port)
{}

fp::com::ConnectCommand::ConnectCommand(std::string && host ,std::string && port)
: m_host(std::move(host))
, m_port(std::move(port))
{}

void fp::com::ConnectCommand::execute()
{
    fp::env::Environment::simulatorControl().set_simulator_host(m_host);
    fp::env::Environment::simulatorControl().set_simulator_port(static_cast<uint16_t>(stoi(m_port)));
}
