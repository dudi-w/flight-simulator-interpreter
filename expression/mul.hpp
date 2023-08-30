#ifndef MUL_HPP
#define MUL_HPP

#include <memory>

#include "expression.hpp"

<<<<<<< HEAD
namespace fp { // namespace flight plan
=======
namespace fp { // namespace flight gear
>>>>>>> dd66aa6 (name space)
namespace exp { // namespace exp

class Mul : public IExpression
{
public:
    explicit Mul(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second);
    Mul(Mul const& other) = default;
    Mul& operator=(Mul const& other) = default;
    ~Mul() = default;

    float get_value() const override;

private:
    std::shared_ptr<IExpression> m_first;
    std::shared_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif