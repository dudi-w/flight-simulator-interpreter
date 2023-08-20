#ifndef SLEEP_COMMAND_HPP
#define SLEEP_COMMAND_HPP

#include <string>
#include "command.hpp"

namespace fp{ //flight plan
namespace com{ // commands

class SleepCommand : public Command
{
public:
    explicit SleepCommand(std::string const& ms);
    SleepCommand(SleepCommand const& other) = default;
    SleepCommand& operator=(SleepCommand const& other) = default;
    ~SleepCommand() = default;

    virtual void execute() override;

private:
    uint m_ms;
};

}// namespace commands
}// namespace flight plan

#endif
