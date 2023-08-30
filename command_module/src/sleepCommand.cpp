#include  <thread>
#include <chrono>

#include "../includes/sleepCommand.hpp"

fp::com::SleepCommand::SleepCommand(std::unique_ptr<fp::Expression> expr)
: m_expr(std::move(expr))
{}

fp::com::SleepCommand::SleepCommand(std::unique_ptr<fp::Expression> && expr)
: m_expr(std::move(expr))
{}

void fp::com::SleepCommand::execute()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
