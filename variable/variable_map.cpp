#include <iostream>

#include "variable_map.hpp"

namespace fp { // namespace flight plan
namespace var { // namespace var

void VariableMap::insert(std::string const& variable_name, std::shared_ptr<IVariable> variable)
{
    m_map.insert({variable_name, variable});
}

float VariableMap::get_variable_value(std::string const& variable_name) const
{
    try
    {
        return m_map.at(variable_name)->get_value();
    }
    catch(const std::out_of_range& e)
    {
        throw std::runtime_error("Variable not found: " + variable_name);
    }
}

void VariableMap::set_variable_value(std::string const& variable_name, float new_value)
{
    try
    {
        m_map.at(variable_name)->set(new_value);
    }
    catch(const std::out_of_range& e)
    {
        throw std::runtime_error("Variable not found: " + variable_name);
    }
}

} //namespace var
} //namespace fp
