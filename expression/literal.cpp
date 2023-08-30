#include "literal.hpp"

<<<<<<< HEAD
namespace fp { // namespace flight plan
=======
namespace fp { // namespace flight gear
>>>>>>> dd66aa6 (name space)
namespace exp { // namespace exp

Literal::Literal(std::string const& num)
{
    m_num = std::stof(num);   
}

float Literal::get_value() const
{
    return m_num;
}

} //namespace exp
} //namespace fp
