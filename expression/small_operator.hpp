#ifndef SMALL_OPERATOR_HPP
#define SMALL_OPERATOR_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class SmallOperator : public IExpression
{
public:
    explicit SmallOperator(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second);
    SmallOperator(SmallOperator const& other) = delete;
    SmallOperator& operator=(SmallOperator const& other) = delete;
    ~SmallOperator() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
