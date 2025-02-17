#ifndef SLEEP_COMMAND_HPP
#define SLEEP_COMMAND_HPP

#include <string>
#include <memory>

#include "command.hpp"
#include "expression.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class SleepCommand : public Command
{
public:
    explicit SleepCommand(std::unique_ptr<fp::exp::Expression> && expr);
    SleepCommand(SleepCommand const& other) = delete;
    SleepCommand& operator=(SleepCommand const& other) = delete;
    ~SleepCommand() = default;

    virtual void execute() override;

private:
    std::unique_ptr<fp::exp::Expression> m_expr;
};

}// namespace commands
}// namespace flight plan

#endif
