#ifndef VARIABLE_EXPRESSION_HPP
#define VARIABLE_EXPRESSION_HPP

#include <string>

#include "expression.hpp"

<<<<<<< HEAD
namespace fp { // namespace flight plan
namespace exp { // namespace exp
=======
namespace fg { // namespace flight gear
>>>>>>> 3900797 (variable expression)

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

<<<<<<< HEAD
} //namespace exp
} //namespace fp
=======
} //namespace
>>>>>>> 3900797 (variable expression)

#endif
