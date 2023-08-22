#ifndef ASSIGNMENT_COMMAND_HPP
#define ASSIGNMENT_COMMAND_HPP

#include <string>
#include <memory>

#include "command.hpp"
#include "../expression.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class AssigmentCommand : public Command
{
public:
    explicit AssigmentCommand(std::string const& variableName ,fp::Expression const& exp);
    explicit AssigmentCommand(std::string const& variableName ,std::shared_ptr<fp::Expression> exp);
    explicit AssigmentCommand(std::string const& variableName ,fp::Expression && exp);
    AssigmentCommand(AssigmentCommand const& other) = default;
    AssigmentCommand& operator=(AssigmentCommand const& other) = default;
    ~AssigmentCommand() = default;

    virtual void execute() override;

private:
    std::string m_variableName;
    std::shared_ptr<fp::Expression> m_exp;
};

}// namespace commands
}// namespace flight plan

#endif
