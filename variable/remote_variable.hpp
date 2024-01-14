#ifndef BIND_VARIABLE_HPP
#define BIND_VARIABLE_HPP

#include <string>
#include <atomic>

#include "variable.hpp"

namespace fp { // namespace flight plan
namespace var { // namespace var

class RemoteVariable : public IVariable
{
public:
    explicit RemoteVariable(std::string const& variable_path, float variable_value);
    explicit RemoteVariable(std::string && variable_path, float variable_value);
    explicit RemoteVariable(std::string const& variable_path);
    explicit RemoteVariable(std::string && variable_path);
    RemoteVariable(RemoteVariable const& other) = default;
    RemoteVariable& operator=(RemoteVariable const& other) = delete;
    ~RemoteVariable() = default;

    float get_value() const override;
    void set_value(float new_value) override;

private:
    const std::string m_variable_path;
};

} //namespace var
} //namespace fp

#endif
