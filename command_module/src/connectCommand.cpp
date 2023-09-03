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

fp::ConnectCommand::execute()
{
    fp::env::Environment::initialization_client(stoi(m_host), stoi(m_port));
}