#include "variable_map.hpp"

namespace fg { // namespace flight gear

void VariableMap::insert(std::string const& variable_name, std::shared_ptr<IVariable> variable)
{
    m_map.insert({variable_name, variable});
}

IVariable& VariableMap::at(std::string const& variable_name) const
{
    try
    {
        return *(m_map.at(variable_name));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';//TODO my exception
    }
}

IVariable& VariableMap::operator[](std::string const& variable_name) const
{
    return at(variable_name);
}

} //namespace
