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

    std::unordered_map<std::string, std::shared_ptr<IVariable>> get_map() const;
    void insert(std::string const& str, std::shared_ptr<IVariable> variable);

private:
    std::unordered_map<std::string, std::shared_ptr<IVariable>> m_map;
};

} //namespace

#endif