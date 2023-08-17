#ifndef SLEEP_COMMAND_HPP
#define SLEEP_COMMAND_HPP

#include <chrono>
#include <string>

#include "includes/command.hpp"

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
    std::chrono::duration<int,std::milli> m_ms;
};

}// namespace flight plan

#endif
