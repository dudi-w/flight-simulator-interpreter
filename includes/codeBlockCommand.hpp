#ifndef CODE_BLOCK_COMMAND_HPP
#define CODE_BLOCK_COMMAND_HPP

#include <vector>

#include "includes/command.hpp"

namespace fp { //flight plan

class CodeBlockCommand : public Command
{
public:
    explicit CodeBlockCommand(std::vector<fp::Command> const& commands);
    CodeBlockCommand(CodeBlockCommand const& other) = default;
    CodeBlockCommand& operator=(CodeBlockCommand const& other) = default;
    ~CodeBlockCommand() = default;

    virtual void execute() override;

private:
    std::vector<fp::Command> m_commands;
};

}// namespace flight plan

#endif
