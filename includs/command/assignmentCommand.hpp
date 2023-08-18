#ifndef ASSIGNMENT_COMMAND_HPP
#define ASSIGNMENT_COMMAND_HPP

#include <string>

#include "includs/command.hpp"
#include "includs/expression.hpp"

namespace fp { //flight plan

class AssigmentCommand : public Command
{
public:
    explicit AssigmentCommand(std::string const& variableName ,fp::Expression const& exp);
    AssigmentCommand(AssigmentCommand const& other) = default;
    AssigmentCommand& operator=(AssigmentCommand const& other) = default;
    ~AssigmentCommand() = default;

    virtual void execute() override;

private:
    std::string m_variableName;
    fp::Expression const& m_exp;
    

};

}// namespace flight plan

#endif
