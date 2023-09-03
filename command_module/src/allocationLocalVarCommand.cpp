#include "allocationLocalVarCommand.hpp"
#include "environment.hpp"

fp::com::AllocationLocalVarCommand::AllocationLocalVarCommand(std::string const& variableName)
: m_variableName(variableName)
{}

fp::com::AllocationLocalVarCommand::AllocationLocalVarCommand(std::string && variableName)
: m_variableName(std::move(variableName))
{}

void fp::com::AllocationLocalVarCommand::execute()
{
    fp::env::Environment::insert_to_map(m_variableName, std::make_unique<fp::LocalVer>(0))
}
