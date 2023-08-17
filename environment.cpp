#include "environment.hpp"

namespace fg { // namespace flight gear

Environment::Environment(std::ostream& output_stream)
: m_output_stream(output_stream)
{}

Environment& Environment::create_instance(std::ostream& output_stream)
{
    static Environment instance(output_stream);
    return instance;
}

VariableMap& Environment::get_map()
{
    return m_variable_map;
}

void Environment::set_output_stream(std::ostream& output_stream)
{
    m_output_stream.rdbuf(output_stream.rdbuf());
}

void Environment::print(std::string const& message)
{
    m_output_stream << message << std::endl;
}

} //namespace