#include "openDataServerCommand.hpp"
#include "environment.hpp"

fp::OpenServerCommand::OpenServerCommand(std::string const& port, std::string const& ups)
: m_port(stoi(port))
, m_ups(stoi(ups))
{}

fp::OpenServerCommand::OpenServerCommand(std::string && port, std::string && ups)
: m_port(stoi(std::move(port)))
, m_ups(stoi(std::move(ups)))
{}

void fp::com::OpenServerCommand::execute()
{
    fp::env::Environment::initialization_server(stoi(m_port), stoi(m_ups));
    
    if(!system("fgfs --generic=socket,out," + m_ups + ",127.0.0.1," + m_port + ",tcp,generic_json_format --telnet=socket,in,10,1270.0.1,5402,tcp --httpd=8080"))
        throw; //TODO my exption;
}
