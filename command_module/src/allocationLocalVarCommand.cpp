#include "allocationLocalVarCommand.hpp"

fp::com::AllocationLocalVarCommand::AllocationLocalVarCommand(std::string const& variableName)
: m_variableName(variableName)
{}

fp::com::AllocationLocalVarCommand::AllocationLocalVarCommand(std::string && variableName)
: m_variableName(std::move(variableName))
{}

void fp::com::AllocationLocalVarCommand::execute()
{
    fp::environment::map.insert(m_variableName , std::make_unique<fp::LocalVer>(0));
}
