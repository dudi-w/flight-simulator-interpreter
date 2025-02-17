#include "printExpCommand.hpp"
#include "environment.hpp"


fp::com::PrintExpCommand::PrintExpCommand(std::unique_ptr<fp::exp::Expression> && expr)
: m_expr(std::move(expr))
{}

void fp::com::PrintExpCommand::execute()
{
    float num = m_expr->get_value();
    fp::env::Environment::print_float(num);
}
