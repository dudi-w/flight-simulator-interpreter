#ifndef PRINT_VAR_COMMAND_HPP
#define PRINT_VAR_COMMAND_HPP

#include <string>

#include "includes/command.hpp"

namespace fp { //flight plan

class PrintStringCommand : public Command
{
public:
    explicit PrintStringCommand(std::string const& variableName);
    PrintStringCommand(PrintStringCommand const& other) = default;
    PrintStringCommand& operator=(PrintStringCommand const& other) = default;
    ~PrintStringCommand() = default;

    virtual void execute() override;

private:
    std::string m_variableName;
};

}// namespace flight plan

#endif
