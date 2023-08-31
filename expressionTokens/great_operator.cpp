#include "great_operator.hpp"

namespace fp { // namespace flight plain

GreatOperator::GreatOperator(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second)
: m_first(first)
, m_second(second)
{}

float GreatOperator::get_value() const
{
    float first_value = m_first->get_value();
    float second_value = m_second->get_value();
    if(first_value > second_value) {
        return 1;
    }
    return 0;
}

} //namespace fp
