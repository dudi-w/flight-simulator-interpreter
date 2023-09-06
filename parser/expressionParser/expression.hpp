#ifndef I_EXPRESSION_HPP
#define I_EXPRESSION_HPP

namespace fp{ // namespace flight plain

class IExpression
{
public:
    virtual ~IExpression() = default;

    virtual float get_value() const = 0;
};

} //namespace fp

#endif
