#ifndef SMALL_OPERATOR_HPP
#define SMALL_OPERATOR_HPP

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

} //namespace exp
} //namespace fp

#endif
