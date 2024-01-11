#include <thread>
#include <chrono>

#include "sleepCommand.hpp"

fp::com::SleepCommand::SleepCommand(std::unique_ptr<fp::exp::Expression> expr)
: m_expr(std::move(expr))
{}

fp::com::SleepCommand::SleepCommand(std::unique_ptr<fp::exp::Expression> && expr)
: m_expr(std::move(expr))
{}

void fp::com::SleepCommand::execute()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int64_t>(m_expr->get_value())));
}
