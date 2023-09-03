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
    explicit WhileCommand(std::unique_ptr<fp::Expression> expr, std::unique_ptr<Command> command);
    explicit WhileCommand(std::unique_ptr<fp::Expression> && expr, std::unique_ptr<Command> && command);
    WhileCommand(WhileCommand const& other) = default;
    WhileCommand& operator=(WhileCommand const& other) = default;
    ~WhileCommand() = default;

    virtual void execute() override;

private:
    std::unique_ptr<fp::Expression> m_exp;
    std::unique_ptr<Command> m_command;
};

}// namespace commands
}// namespace flight plan

#endif
