#ifndef CONNECT_COMMAND_HPP
#define CONNECT_COMMAND_HPP

#include <string>
#include "command.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class ConnectCommand : public Command
{
public:
    explicit ConnectCommand(std::string const& host ,std::string const& port);
    ConnectCommand(ConnectCommand const& other) = default;
    ConnectCommand& operator=(ConnectCommand const& other) = default;
    ~ConnectCommand() = default;

    virtual void execute() override;

private:
    uint m_host;
    uint m_port;

};

}// namespace commands
}// namespace flight plan

#endif
