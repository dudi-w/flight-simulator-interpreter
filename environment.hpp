#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <iostream>

#include "variable_map.hpp"

namespace fg { // namespace flight gear

class Environment
{
public:
    Environment(Environment const& other) = delete;
    Environment& operator=(Environment const& other) = delete;
    ~Environment() = default;

    static Environment& create_instance(std::ostream& output_stream);
    VariableMap& get_map();
    void set_output_stream(std::ostream& output_stream);
    void print(std::string const& message);

private:
    Environment(std::ostream& output_stream);

private:
    VariableMap m_variable_map;
    std::ostream& m_output_stream;
};

} //namespace

#endif
