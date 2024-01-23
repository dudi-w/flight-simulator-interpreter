#ifndef GREAT_EQUAL_OPERATOR_HPP
#define GREAT_EQUAL_OPERATOR_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class GreatEqualOperator : public IExpression
{
public:
    explicit GreatEqualOperator(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second);
    GreatEqualOperator(GreatEqualOperator const& other) = delete;
    GreatEqualOperator& operator=(GreatEqualOperator const& other) = delete;
    ~GreatEqualOperator() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
