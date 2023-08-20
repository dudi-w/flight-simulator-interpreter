#ifndef OPEN_SERVER_HPP
#define OPEN_SERVER_HPP

#include <string>
#include "includs/command.hpp"

namespace fp { //flight plan

class OpenServerCommand : public Command
{
public:
    explicit OpenServerCommand(std::string const& port, std::string const& ups);
    OpenServerCommand(OpenServerCommand const& other) = default;
    OpenServerCommand& operator=(OpenServerCommand const& other) = default;
    ~OpenServerCommand() = default;

    virtual void execute() override;

private:
    uint m_port;
    uint m_ups;
};

}// namespace flight plan

#endif
