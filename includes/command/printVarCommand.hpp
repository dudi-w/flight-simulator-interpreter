#ifndef PRINT_VAR_COMMAND_HPP
#define PRINT_VAR_COMMAND_HPP

#include <string>

#include "includs/command.hpp"

namespace fp { //flight plan

class PrintVarCommand : public Command
{
public:
    explicit PrintVarCommand(std::string const& variableName);
    PrintVarCommand(PrintVarCommand const& other) = default;
    PrintVarCommand& operator=(PrintVarCommand const& other) = default;
    ~PrintVarCommand() = default;

    virtual void execute() override;

private:
    std::string m_variableName;
};

}// namespace flight plan

#endif
