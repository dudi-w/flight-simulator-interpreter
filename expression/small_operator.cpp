#include "small_operator.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

SmallOperator::SmallOperator(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second)
: m_first(std::move(first))
, m_second(std::move(second))
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
