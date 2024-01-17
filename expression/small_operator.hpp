#ifndef SMALL_OPERATOR_HPP
#define SMALL_OPERATOR_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class LessOperator : public IExpression
{
public:
    explicit LessOperator(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second);
    LessOperator(LessOperator const& other) = delete;
    LessOperator& operator=(LessOperator const& other) = delete;
    ~LessOperator() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
