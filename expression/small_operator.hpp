#ifndef SMALL_OPERATOR_HPP
#define SMALL_OPERATOR_HPP

#include <memory>

#include "expression.hpp"

namespace fg { // namespace flight gear

class SmallOperator : public IExpression
{
public:
    explicit SmallOperator(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second);
    SmallOperator(SmallOperator const& other) = default;
    SmallOperator& operator=(SmallOperator const& other) = default;
    ~SmallOperator() = default;

    float get_value() const override;

private:
    std::shared_ptr<IExpression> m_first;
    std::shared_ptr<IExpression> m_second;
};

} //namespace

#endif