#ifndef OPEN_SERVER_HPP
#define OPEN_SERVER_HPP

#include <string>

#include "command.hpp"

namespace fp { //flight plan
namespace com{ // commands

class OpenServerCommand : public Command
{
public:
    explicit OpenServerCommand(std::string const& port, std::string const& ups);
    explicit OpenServerCommand(std::string && port, std::string && ups);
    OpenServerCommand(OpenServerCommand const& other) = default;
    OpenServerCommand& operator=(OpenServerCommand const& other) = delete;
    ~OpenServerCommand() = default;

    virtual void execute() override;

private:
    const std::string m_port;
    const std::string m_ups;
};

}// namespace commands
}// namespace flight plan

#endif
