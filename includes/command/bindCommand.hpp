#ifndef BIND_COMMAND_HPP
#define BIND_COMMAND_HPP

#include <string>

#include "command.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class BindCommand : public Command
{
public:
    explicit BindCommand(std::string const& variableName ,std::string const& path);
    BindCommand(BindCommand const& other) = default;
    BindCommand& operator=(BindCommand const& other) = default;
    ~BindCommand() = default;

    virtual void execute() override;

private:
    std::string m_variableName;
    std::string m_path;
};

}// namespace commands
}// namespace flight plan

#endif
