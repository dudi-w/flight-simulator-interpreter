#include "literal.hpp"

namespace fp { // namespace flight gear
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
