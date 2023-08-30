#include <stdexcept>

#include "div.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

Div::Div(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second)
: m_first(first)
, m_second(second)
{}

float Div::get_value() const
{
    float first_value = m_first->get_value();
    float second_value = m_second->get_value();
    
    if(second_value == 0) {
        throw std::runtime_error("Division by zero error!");
    }
    
    return first_value / second_value;
}

} //namespace exp
} //namespace fp
