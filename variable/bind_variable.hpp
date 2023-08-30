#ifndef BIND_VARIABLE_HPP
#define BIND_VARIABLE_HPP

#include <string>
#include <atomic>

#include "variable.hpp"

namespace fp { // namespace flight plan
namespace var { // namespace var

class BindVariable : public IVariable
{
public:
    explicit BindVariable(std::string const& variable_name, std::string variable_path, float variable_value);
    BindVariable(BindVariable const& other) = default;
    BindVariable& operator=(BindVariable const& other) = default;
    ~BindVariable() = default;

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
