#ifndef LOCAL_VARIABLE_HPP
#define LOCAL_VARIABLE_HPP

#include <string>

#include "variable.hpp"

namespace fg { // namespace flight gear

class LocalVariable : public IVariable
{
public:
    explicit LocalVariable(std::string const& variable_name, float variable_value);
    LocalVariable(LocalVariable const& other) = default;
    LocalVariable& operator=(LocalVariable const& other) = default;
    ~LocalVariable() = default;

    float get_value() const override;
    void set(float new_value) override;

private:
    std::string m_variable_name;
    float m_variable_value;
};

} //namespace

#endif
