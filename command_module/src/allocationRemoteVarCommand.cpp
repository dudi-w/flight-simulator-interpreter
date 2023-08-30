#ifndef ALLOCATION_REMOTE_VAR_COMMAND_HPP
#define ALLOCATION_REMOTE_VAR_COMMAND_HPP

#include <string>
#include <memory>


#include "command.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class AllocationRemoteVarCommand : public Command
{
public:
    explicit AllocationRemoteVarCommand(std::string const& variableName);
    explicit AllocationRemoteVarCommand(std::string && variableName);
    AllocationRemoteVarCommand(AllocationRemoteVarCommand const& other) = default;
    AllocationRemoteVarCommand& operator=(AllocationRemoteVarCommand const& other) = default;
    ~AllocationRemoteVarCommand() = default;

    virtual void execute() override;

private:
    const std::string m_variableName;
};

}// namespace commands
}// namespace flight plan

#endif
