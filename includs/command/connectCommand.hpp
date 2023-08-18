#ifndef CONNECT_COMMAND_HPP
#define CONNECT_COMMAND_HPP

#include <string>
#include "includs/command.hpp"

namespace fp { //flight plan

class ConnectCommand : public Command
{
public:
    explicit ConnectCommand(std::string const& host ,std::string const& port);
    ConnectCommand(ConnectCommand const& other) = default;
    ConnectCommand& operator=(ConnectCommand const& other) = default;
    ~ConnectCommand() = default;

    virtual void execute() override;

private:
    std::string m_host;
    std::string m_port;

};

}// namespace flight plan

#endif
