#ifndef COMMAND_HPP
#define COMMAND_HPP

namespace fp{
    
class Command
{
public:
    virtual ~Command() = default;

    virtual void exeute() = 0;
};

} // namespace fp

#endif