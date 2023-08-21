#ifndef PRINT_STRING_COMMAND_HPP
#define PRINT_STRING_COMMAND_HPP

#include <string>

#include "command.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class PrintStringCommand : public Command
{
public:
    explicit PrintStringCommand(std::string const& message);
    PrintStringCommand(PrintStringCommand const& other) = default;
    PrintStringCommand& operator=(PrintStringCommand const& other) = default;
    ~PrintStringCommand() = default;

    virtual void execute() override;

private:
    std::string m_message;
};

}// namespace commands
}// namespace flight plan

#endif
