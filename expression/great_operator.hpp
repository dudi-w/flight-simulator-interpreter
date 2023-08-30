#ifndef GREAT_OPERATOR_HPP
#define GREAT_OPERATOR_HPP

#include <memory>

#include "expression.hpp"

<<<<<<< HEAD
<<<<<<< HEAD
namespace fp { // namespace flight plan
=======
namespace fp { // namespace flight gear
>>>>>>> dd66aa6 (name space)
=======
namespace fp { // namespace flight plan
>>>>>>> 25583f8 (namespace)
namespace exp { // namespace exp

class GreatOperator : public IExpression
{
public:
    explicit GreatOperator(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second);
    GreatOperator(GreatOperator const& other) = default;
    GreatOperator& operator=(GreatOperator const& other) = default;
    ~GreatOperator() = default;

    float get_value() const override;

private:
    std::shared_ptr<IExpression> m_first;
    std::shared_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
