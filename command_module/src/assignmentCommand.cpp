#include "../../includes/command/assignmentCommand.hpp"

fp::com::AssigmentCommand::AssigmentCommand(std::string const& variableName ,fp::Expression const& exp)
: m_variableName(variableName)
, m_exp(std::make_shared<fp::Expression>(exp))
{}

fp::com::AssigmentCommand::AssigmentCommand(std::string const& variableName ,std::shared_ptr<fp::Expression> exp)
: m_variableName(variableName)
, m_exp(exp)
{}

fp::com::AssigmentCommand::AssigmentCommand(std::string const& variableName ,fp::Expression && exp)
: m_variableName(variableName)
, m_exp(std::make_shared<fp::Expression>(exp))
{}

void fp::com::AssigmentCommand::execute()
{
    fp::environment::map.at(m_variableName) = m_exp->get();
}
