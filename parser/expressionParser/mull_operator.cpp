#include "mull_operator.hpp"

namespace fp { // namespace flight gear

Mul::Mul(std::unique_ptr<IExpression>  first, std::unique_ptr<IExpression>  second)
: m_first(std::move(first))
, m_second(std::move(second))
{}

float Mul::get_value() const
{
    float first_value = m_first->get_value();
    float second_value = m_second->get_value();
    return first_value * second_value;
}

} //namespace