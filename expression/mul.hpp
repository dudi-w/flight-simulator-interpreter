#ifndef MUL_HPP
#define MUL_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class Mul : public IExpression
{
public:
    explicit Mul(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second);
    Mul(Mul const& other) = delete;
    Mul& operator=(Mul const& other) = delete;
    ~Mul() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif