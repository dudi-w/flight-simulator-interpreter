#ifndef SMALL_OPERATOR_HPP
#define SMALL_OPERATOR_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight gear

class SmallOperator : public IExpression
{
public:
    explicit SmallOperator(std::unique_ptr<IExpression>  first, std::unique_ptr<IExpression>  second);
    SmallOperator(SmallOperator const& other) = default;
    SmallOperator& operator=(SmallOperator const& other) = default;
    ~SmallOperator() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace

#endif