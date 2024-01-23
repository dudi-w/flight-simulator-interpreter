#ifndef LESS_EQUAL_OPERATOR_HPP
#define LESS_EQUAL_OPERATOR_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class LessEqualOperator : public IExpression
{
public:
    explicit LessEqualOperator(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second);
    LessEqualOperator(LessEqualOperator const& other) = delete;
    LessEqualOperator& operator=(LessEqualOperator const& other) = delete;
    ~LessEqualOperator() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
