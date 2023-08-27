#ifndef ASSIGNMENT_COMMAND_HPP
#define ASSIGNMENT_COMMAND_HPP

#include <string>
#include <memory>

#include "command.hpp"
#include "../includs/expression.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class AssigmentCommand : public Command
{
public:
    explicit AssigmentCommand(std::string const& variableName ,std::unique_ptr<fp::Expression> expr);
    explicit AssigmentCommand(std::string && variableName ,std::unique_ptr<fp::Expression> expr);
    explicit AssigmentCommand(std::string && variableName ,std::unique_ptr<fp::Expression> && expr);
    AssigmentCommand(AssigmentCommand const& other) = default;
    AssigmentCommand& operator=(AssigmentCommand const& other) = default;
    ~AssigmentCommand() = default;

    virtual void execute() override;

private:
    const std::string m_variableName;
    std::shared_ptr<fp::Expression> m_expr;
};

}// namespace commands
}// namespace flight plan

#endif
