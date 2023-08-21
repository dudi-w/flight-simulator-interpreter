#ifndef WHILE_COMMAND_HPP
#define WHILE_COMMAND_HPP

#include <memory>

#include "../expression.hpp"
#include "command.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class WhileCommand : public Command
{
public:
    explicit WhileCommand(fp::Expression const& exp, Command const& comm);
    explicit WhileCommand(fp::Expression && exp, Command && comm);
    explicit WhileCommand(std::unique_ptr<fp::Expression> exp, std::unique_ptr<Command> comm);
    WhileCommand(WhileCommand const& other) = default;
    WhileCommand& operator=(WhileCommand const& other) = default;
    ~WhileCommand() = default;

    virtual void execute() override;

private:
    std::unique_ptr<fp::Expression> m_exp;
    std::unique_ptr<Command> m_comm;
};

}// namespace commands
}// namespace flight plan

#endif
