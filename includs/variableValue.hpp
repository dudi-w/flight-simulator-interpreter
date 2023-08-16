#ifndef VARIABLE_VALUE_HPP
#define VARIABLE_VALUE_HPP

namespace fp {

class VariableValue
{
public:
    virtual ~VariableValue() = default;

    virtual float get() = 0;
    virtual void set(float value) = 0;
};

}// namespace fp

#endif
