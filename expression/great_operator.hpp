#ifndef GREAT_OPERATOR_HPP
#define GREAT_OPERATOR_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class GreatOperator : public IExpression
{
public:
    explicit GreatOperator(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second);
    GreatOperator(GreatOperator const& other) = default;
    GreatOperator& operator=(GreatOperator const& other) = default;
    ~GreatOperator() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
