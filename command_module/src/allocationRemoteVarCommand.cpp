#include "allocationRemoteVarCommand.hpp"
#include "environment.hpp"
#include "remote_variable.hpp"

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
    fp::env::Environment::getDataMap().insert(m_variablePath);
    fp::env::Environment::insert_to_map(m_variableName , std::make_unique<fp::var::RemoteVariable>(std::move(m_variablePath),0));
}
