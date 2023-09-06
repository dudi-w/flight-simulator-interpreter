#ifndef LOCAL_VARIABLE_HPP
#define LOCAL_VARIABLE_HPP

#include <string>

#include "variable.hpp"

namespace fp { // namespace flight plan
namespace var { // namespace var

class LocalVariable : public IVariable
{
public:
    LocalVariable() = default;
    explicit LocalVariable(float variable_value);
    LocalVariable(LocalVariable const& other) = default;
    LocalVariable& operator=(LocalVariable const& other) = default;
    ~LocalVariable() = default;

    float get_value() const override;
    void set_value(float new_value) override;

private:
    float m_variable_value;
};

} //namespace var
} //namespace fp

#endif
