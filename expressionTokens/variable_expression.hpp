#ifndef VARIABLE_EXPRESSION_HPP
#define VARIABLE_EXPRESSION_HPP

#include <string>

#include "expression.hpp"

namespace fp { // namespace flight gear

class VariableExpression : public IExpression
{
public:
    explicit VariableExpression(std::string const& variable_name);
    VariableExpression(VariableExpression const& other) = default;
    VariableExpression& operator=(VariableExpression const& other) = default;
    ~VariableExpression() = default;

    float get_value() const override;

private:
    std::string m_variable_name;
};

} //namespace

#endif
