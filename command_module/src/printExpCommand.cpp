#include "../includes/printExpCommand.hpp"

fp::com::PrintExpCommand::PrintExpCommand(std::shared_ptr<fp::Expression> exp)
: m_exp(exp)
{}

void fp::com::PrintExpCommand::execute()
{
    float num = m_exp->get();
    fp::environment::ostream.printF(num);
}
