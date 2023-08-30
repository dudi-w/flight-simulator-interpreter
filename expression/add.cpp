#include "add.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

Add::Add(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second)
: m_first(first)
, m_second(second)
{}

float Add::get_value() const
{
    float first_value = m_first->get_value();
    float second_value = m_second->get_value();
    return first_value + second_value;
}

} //namespace exp
} //namespace fp
