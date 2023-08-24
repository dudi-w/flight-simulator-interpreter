#ifndef PRINT_VAR_COMMAND_HPP
#define PRINT_VAR_COMMAND_HPP

#include <string>
#include <memory>

#include "command.hpp"
#include "../expression.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class PrintExpCommand : public Command
{
public:
    explicit PrintExpCommand(std::unique_ptr<fp::Expression> expr);
    PrintExpCommand(PrintExpCommand const& other) = default;
    PrintExpCommand& operator=(PrintExpCommand const& other) = default;
    ~PrintExpCommand() = default;

    virtual void execute() override;

private:
    std::unique_ptr<fp::Expression> m_expr;
};

}// namespace commands
}// namespace flight plan

#endif
