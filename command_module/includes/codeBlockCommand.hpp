#ifndef CODE_BLOCK_COMMAND_HPP
#define CODE_BLOCK_COMMAND_HPP

#include <vector>
#include <memory>

#include "command.hpp"

namespace fp{ //flight plan

using Commands = std::vector<std::unique_ptr<fp::com::Command>>;

namespace com{ // commands

class CodeBlockCommand : public Command
{
public:
    explicit CodeBlockCommand(fp::Commands && commands);
    CodeBlockCommand(CodeBlockCommand const& other) = delete;
    CodeBlockCommand& operator=(CodeBlockCommand const& other) = delete;
    ~CodeBlockCommand() = default;

    virtual void execute() override;

private:
    fp::Commands m_commands;
};

}// namespace commands
}// namespace flight plan

#endif
