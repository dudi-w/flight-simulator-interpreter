#ifndef EQULE_OPERATOR_HPP
#define EQULE_OPERATOR_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class EquleOperator : public IExpression
{
public:
    explicit EquleOperator(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second);
    EquleOperator(EquleOperator const& other) = delete;
    EquleOperator& operator=(EquleOperator const& other) = delete;
    ~EquleOperator() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
