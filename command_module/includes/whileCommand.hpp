#ifndef WHILE_COMMAND_HPP
#define WHILE_COMMAND_HPP

#include <memory>

#include "expression.hpp"
#include "command.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class WhileCommand : public Command
{
public:
    explicit WhileCommand(std::unique_ptr<fp::exp::Expression> && expr, std::unique_ptr<Command> && command);
    WhileCommand(WhileCommand const& other) = delete;
    WhileCommand& operator=(WhileCommand const& other) = delete;
    ~WhileCommand() = default;

    virtual void execute() override;

private:
    std::unique_ptr<fp::exp::Expression> m_exp;
    std::unique_ptr<Command> m_command;
};

}// namespace commands
}// namespace flight plan

#endif
