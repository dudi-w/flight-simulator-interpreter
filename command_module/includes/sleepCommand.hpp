#ifndef SLEEP_COMMAND_HPP
#define SLEEP_COMMAND_HPP

#include <string>
#include <memory>

#include "command.hpp"
#include "../includs/expression.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class SleepCommand : public Command
{
public:
    explicit SleepCommand(std::unique_ptr<fp::Expression> expr);
    explicit SleepCommand(std::unique_ptr<fp::Expression> && expr);
    SleepCommand(SleepCommand const& other) = default;
    SleepCommand& operator=(SleepCommand const& other) = default;
    ~SleepCommand() = default;

    virtual void execute() override;

private:
    std::unique_ptr<fp::Expression> m_expr;
};

}// namespace commands
}// namespace flight plan

#endif
