#ifndef WHILE_COMMAND_HPP
#define WHILE_COMMAND_HPP

#include <memory>

#include "includs/expression.hpp"
#include "includs/command.hpp"

namespace fp { //flight plan

class WhileCommand : public Command
{
public:
    explicit WhileCommand(fp::Expression const& exp, fp::Command const& comm);
    WhileCommand(WhileCommand const& other) = default;
    WhileCommand& operator=(WhileCommand const& other) = default;
    ~WhileCommand() = default;

    virtual void execute() override;

private:
    std::unique_ptr<fp::Expression> m_exp;
    std::unique_ptr<fp::Command> m_comm;
};

}// namespace flight plan

#endif
