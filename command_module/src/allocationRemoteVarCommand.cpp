#include "allocationRemoteVarCommand.hpp"

fp::com::AllocationRemoteVarCommand::AllocationRemoteVarCommand(std::string const& variableName, std::string const& variablePath)
: m_variableName(variableName)
, m_variablePath(variablePath)
{}

fp::com::AllocationRemoteVarCommand::AllocationRemoteVarCommand(std::string && variableName, std::string && variablePath)
: m_variableName(std::move(variableName))
, m_variablePath(std::move(variablePath))
{}

void fp::com::AllocationRemoteVarCommand::execute()
{
    fp::environment::map.insert(m_variableName , std::make_unique<fp::bindVar>(0, m_variablePath));
}
