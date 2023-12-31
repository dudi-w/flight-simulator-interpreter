#include "remote_variable.hpp"

namespace fp { // namespace flight plan
namespace var { // namespace var

RemoteVariable::RemoteVariable(std::string const& variable_path, float variable_value)
: m_variable_path(variable_path)
{
    set_value(variable_value);
}

RemoteVariable::RemoteVariable(std::string && variable_path, float variable_value)
: m_variable_path(std::move(variable_path))
{
    set_value(variable_value);
}

RemoteVariable::RemoteVariable(std::string const& variable_path)
: m_variable_path(variable_path)
{}

RemoteVariable::RemoteVariable(std::string && variable_path)
: m_variable_path(std::move(variable_path))
{}

float RemoteVariable::get_value() const
{
    return fp::env::DataMap.get(m_variable_path);
}

void RemoteVariable::set_value(float new_value)
{
    fp::env::simulator.setVariableValue(m_variable_path , new_value);
}

} //namespace var
} //namespace fp
