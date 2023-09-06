#include <stdexcept>

#include "div.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

Div::Div(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second)
: m_first(std::move(first))
, m_second(std::move(second))
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
