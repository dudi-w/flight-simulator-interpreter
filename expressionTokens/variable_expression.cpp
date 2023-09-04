#include "variable_expression.hpp"

namespace fp { // namespace flight gear

VariableExpression::VariableExpression(std::string const& variable_name)
: m_variable_name(variable_name)
{}

float VariableExpression::get_value() const
{
    // Environment& environment = Environment::get_instance(std::cout);
    // float value = environment.get_variable(m_variable_name).get_value();
    float value = 3.5;
    return value;
}

} //namespace
