#include "variable_map.hpp"

namespace fg { // namespace flight gear

std::unordered_map<std::string, std::shared_ptr<IVariable>> VariableMap::get_map() const
{
    return m_map;
}

void VariableMap::insert(std::string const& str, std::shared_ptr<IVariable> variable)
{
    m_map[str] = variable;
}

} //namespace
