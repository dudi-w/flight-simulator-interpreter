#include "add.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

Add::Add(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second)
: m_first(std::move(first))
, m_second(std::move(second))
{}

float Add::get_value() const
{
    float first_value = m_first->get_value();
    float second_value = m_second->get_value();
    return first_value + second_value;
}

} //namespace exp
} //namespace fp
