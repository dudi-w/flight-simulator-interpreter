#ifndef NOT_EQULE_OPERATOR_HPP
#define NOT_EQULE_OPERATOR_HPP

#include <memory>
#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class NotEqualOperator : public IExpression
{
public:
    explicit NotEqualOperator(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second);
    NotEqualOperator(NotEqualOperator const& other) = delete;
    NotEqualOperator& operator=(NotEqualOperator const& other) = delete;
    ~NotEqualOperator() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
