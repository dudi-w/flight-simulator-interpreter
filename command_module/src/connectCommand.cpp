#include "../../includs/command/connectCommand.hpp"

fp::ConnectCommand::ConnectCommand(std::string const& host ,std::string const& port)
: m_host(stoul(host))
, m_port(stoul(port))
{}

fp::ConnectCommand::execute()
{
    fp::environment::client.initioaze(m_host, m_port);
}