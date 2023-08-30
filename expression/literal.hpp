#ifndef LITERAL_HPP
#define LITERAL_HPP

#include <string>

#include "expression.hpp"

<<<<<<< HEAD
<<<<<<< HEAD
namespace fp { // namespace flight plan
=======
namespace fp { // namespace flight gear
>>>>>>> dd66aa6 (name space)
=======
namespace fp { // namespace flight plan
>>>>>>> 25583f8 (namespace)
namespace exp { // namespace exp

class Literal : public IExpression
{
public:
    explicit Literal(std::string const& num);
    Literal(Literal const& other) = default;
    Literal& operator=(Literal const& other) = default;
    ~Literal() = default;

    float get_value() const override;

private:
    float m_num;
};

} //namespace exp
} //namespace fp

#endif