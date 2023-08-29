#include "variable_expression.hpp"

namespace fp { // namespace flight gear

VariableExpression::VariableExpression(std::string const& variable_name)
: m_variable_name(variable_name)
{}

float VariableExpression::get_value() const
{
    
}

} //namespace
