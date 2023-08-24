#ifndef I_VARIABLE_HPP
#define I_VARIABLE_HPP

namespace fg { // namespace flight gear

class IVariable
{
public:
    virtual ~IVariable() = default;

    virtual float get_value() const = 0;
    virtual void set(float value) = 0;
};

} //namespace

#endif
