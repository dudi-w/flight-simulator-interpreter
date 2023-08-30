#include "sub.hpp"

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

Sub::Sub(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second)
: m_first(first)
, m_second(second)
{}

float Sub::get_value() const
{
    float first_value = m_first->get_value();
    float second_value = m_second->get_value();
    return first_value - second_value;
}

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
