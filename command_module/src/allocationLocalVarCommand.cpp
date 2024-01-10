#include "allocationLocalVarCommand.hpp"
#include "environment.hpp"
#include "local_variable.hpp"

fp::com::AllocationLocalVarCommand::AllocationLocalVarCommand(std::string const& variableName)
: m_variableName(variableName)
{}

fp::com::AllocationLocalVarCommand::AllocationLocalVarCommand(std::string && variableName)
: m_variableName(std::move(variableName))
{}

void fp::com::AllocationLocalVarCommand::execute()
{
    fp::env::Environment::insert_to_map(std::move(m_variableName), std::make_unique<fp::var::LocalVariable>(0));
}
