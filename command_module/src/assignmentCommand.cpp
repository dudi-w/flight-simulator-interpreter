#include "assignmentCommand.hpp"
#include "environment.hpp"

fp::com::AssigmentCommand::AssigmentCommand(std::string const& variableName ,std::unique_ptr<fp::exp::Expression> expr)
: m_variableName(variableName)
, m_expr(std::move(expr))
{}

fp::com::AssigmentCommand::AssigmentCommand(std::string && variableName ,std::unique_ptr<fp::exp::Expression> && expr)
: m_variableName(std::move(variableName))
, m_expr(std::move(expr))
{}

void fp::com::AssigmentCommand::execute()
{
    fp::env::Environment::set_variable_value(m_variableName, m_expr->get());
}
