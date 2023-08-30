#include "small_operator.hpp"

namespace fp { // namespace flight gear
namespace exp { // namespace exp

SmallOperator::SmallOperator(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second)
: m_first(first)
, m_second(second)
{}

float SmallOperator::get_value() const
{
    float first_value = m_first->get_value();
    float second_value = m_second->get_value();
    if(first_value < second_value) {
        return 1;
    }
    return 0;
}

} //namespace exp
} //namespace fp
