#ifndef I_EXPRESSION_HPP
#define I_EXPRESSION_HPP

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class IExpression
{
public:
    virtual ~IExpression() = default;

    virtual float get_value() const = 0;
};

using Expression = IExpression;

} //namespace exp
} //namespace fp

#endif
