#ifndef COMMAND_HPP
#define COMMAND_HPP

namespace fp{ //flight plan
namespace com{ // commands

    
class Command
{
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
};

}// namespace commands
}// namespace flight plan

#endif
