#ifndef EQULE_OPERATOR_HPP
#define EQULE_OPERATOR_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight gear
namespace exp { // namespace exp

class EquleOperator : public IExpression
{
public:
    explicit EquleOperator(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second);
    EquleOperator(EquleOperator const& other) = default;
    EquleOperator& operator=(EquleOperator const& other) = default;
    ~EquleOperator() = default;

    float get_value() const override;

private:
    std::shared_ptr<IExpression> m_first;
    std::shared_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
