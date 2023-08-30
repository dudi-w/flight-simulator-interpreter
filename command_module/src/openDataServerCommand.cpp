#include "../../includs/command/openDataServerCommand.hpp"


fp::OpenServerCommand::OpenServerCommand(std::string const& port, std::string const& ups)
: m_port(stoi(port))
, m_ups(stoi(ups))
{}

void fp::OpenServerCommand::execute()
{
    fp::environment::server.initioaze(m_port, m_ups);
    if(!system("fgfs --generic=socket,out," + m_ups + ",127.0.0.1," + m_port + ",tcp,generic_json_format --telnet=socket,in,10,1270.0.1,5402,tcp --httpd=8080"))
        throw; //TODO my exption;
}
