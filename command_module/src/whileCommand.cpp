#include "whileCommand.hpp"

fp::com::WhileCommand::WhileCommand(std::unique_ptr<fp::exp::Expression> && exp, std::unique_ptr<Command> && command)
: m_exp(std::move(exp))
, m_command(std::move(command))
{}

void fp::com::WhileCommand::execute()
{
    while(m_exp->get_value()){
        m_command->execute();
    }
}
