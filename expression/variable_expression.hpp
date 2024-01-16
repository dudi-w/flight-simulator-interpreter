#ifndef VARIABLE_EXPRESSION_HPP
#define VARIABLE_EXPRESSION_HPP

#include <string>

#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class VariableExpression : public IExpression
{
public:
    explicit VariableExpression(std::string const& variable_name);
    VariableExpression(VariableExpression const& other) = delete;
    VariableExpression& operator=(VariableExpression const& other) = delete;
    ~VariableExpression() = default;

    float get_value() const override;

private:
    std::string m_variable_name;
};

} //namespace exp
} //namespace fp

#endif
