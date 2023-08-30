#ifndef VARIABLE_MAP_HPP
#define VARIABLE_MAP_HPP

#include <string>
#include <unordered_map>
#include <memory>

#include "variable.hpp"

namespace fg { // namespace flight gear

class VariableMap
{
public:
    VariableMap() = default;
    VariableMap(VariableMap const& other) = default;
    VariableMap& operator=(VariableMap const& other) = default;
    ~VariableMap() = default;

    void insert(std::string const& variable_name, std::shared_ptr<IVariable> variable);
    float get_variable_value(std::string const& variable_name) const;
    void set_variable_value(std::string const& variable_name, float new_value);

private:
    std::unordered_map<std::string, std::shared_ptr<IVariable>> m_map;
};

} //namespace

#endif
