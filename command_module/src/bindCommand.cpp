#include <memory>

#include "../../includes/command/bindCommand.hpp"
#include "bind_variable.hpp"

fp::com::BindCommand::BindCommand(std::string const& variableName ,std::string const& path)
: m_variableName(variableName)
, m_path(path)
{}

fp::com::BindCommand::execute()
{
    fp::environment::map.insert(m_variableName, std::make_shared<fp::BindVariable>(m_path, 0));
}
