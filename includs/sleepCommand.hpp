#ifndef SLEEP_COMMAND_HPP
#define SLEEP_COMMAND_HPP

#include <string>
#include "includs/command.hpp"

namespace fp { //flight plan

class SleepCommand : public Command
{
public:
    explicit SleepCommand(std::string const& ms);
    SleepCommand(SleepCommand const& other) = default;
    SleepCommand& operator=(SleepCommand const& other) = default;
    ~SleepCommand() = default;

    virtual void execute() override;

private:
    float m_ms;
};

}// namespace flight plan

#endif
