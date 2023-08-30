#ifndef DIV_HPP
#define DIV_HPP

#include <memory>

#include "expression.hpp"

<<<<<<< HEAD
<<<<<<< HEAD
namespace fp { // namespace flight plan
namespace exp { // namespace exp
=======
namespace fg { // namespace flight gear
>>>>>>> 07320af (only expression files)
=======
namespace fp { // namespace flight gear
namespace exp { // namespace exp
>>>>>>> dd66aa6 (name space)

class Div : public IExpression
{
public:
    explicit Div(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second);
    Div(Div const& other) = default;
    Div& operator=(Div const& other) = default;
    ~Div() = default;

    float get_value() const override;

private:
    std::shared_ptr<IExpression> m_first;
    std::shared_ptr<IExpression> m_second;
};

<<<<<<< HEAD
<<<<<<< HEAD
} //namespace exp
} //namespace fp
=======
} //namespace
>>>>>>> 07320af (only expression files)
=======
} //namespace exp
} //namespace fp
>>>>>>> dd66aa6 (name space)

#endif
