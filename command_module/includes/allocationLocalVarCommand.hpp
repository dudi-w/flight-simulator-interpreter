#ifndef ALLOCATION_LOCAL_VAR_COMMAND_HPP
#define ALLOCATION_LOCAL_VAR_COMMAND_HPP

#include <string>
#include <memory>

#include "command.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class AllocationLocalVarCommand : public Command
{
public:
    explicit AllocationLocalVarCommand(std::string const& variableName);
    explicit AllocationLocalVarCommand(std::string && variableName);
    AllocationLocalVarCommand(AllocationLocalVarCommand const& other) = default;
    AllocationLocalVarCommand& operator=(AllocationLocalVarCommand const& other) = delete;
    ~AllocationLocalVarCommand() = default;

    virtual void execute() override;

private:
    const std::string m_variableName;
};

}// namespace commands
}// namespace flight plan

#endif
