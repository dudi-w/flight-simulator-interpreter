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
    explicit RemoteVariable(std::string const& variable_name, std::string variable_path, float variable_value);
    RemoteVariable(RemoteVariable const& other) = default;
    RemoteVariable& operator=(RemoteVariable const& other) = default;
    ~RemoteVariable() = default;

    float get_value() const override;
    void set(float new_value) override;

private:
    std::string m_variable_name;
    std::string m_variable_path;
    std::atomic<float> m_variable_value;   
};

} //namespace var
} //namespace fp

#endif
