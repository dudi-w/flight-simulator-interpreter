#ifndef MUL_HPP
#define MUL_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plain

class Mul : public IExpression
{
public:
    explicit Mul(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second);
    Mul(Mul const& other) = default;
    Mul& operator=(Mul const& other) = default;
    ~Mul() = default;

    float get_value() const override;

private:
    std::shared_ptr<IExpression> m_first;
    std::shared_ptr<IExpression> m_second;
};

} //namespace fp

#endif