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
    std::shared_ptr<IVariable> at(std::string const& variable_name) const;
    std::shared_ptr<IVariable> oprator[](std::string const& variable_name) const;

private:
    std::unordered_map<std::string, std::shared_ptr<IVariable>> m_map;
};

} //namespace

#endif
