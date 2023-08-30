#ifndef LITERAL_HPP
#define LITERAL_HPP

#include <string>

#include "expression.hpp"

namespace fp { // namespace flight gear
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