#include "variable_expression.hpp"
#include "../environment/environment.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

VariableExpression::VariableExpression(std::string const& variable_name)
: m_variable_name(variable_name)
{}

float VariableExpression::get_value() const
{
    // Environment& environment = Environment::get_instance(std::cout);
    // float value = environment.get_variable(m_variable_name).get_value();
    return env::Environment::get_variable_value(m_variable_name);
}

} //namespace exp
} //namespace fp
