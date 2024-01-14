#ifndef DIV_HPP
#define DIV_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class Div : public IExpression
{
public:
    explicit Div(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second);
    Div(Div const& other) = delete;
    Div& operator=(Div const& other) = delete;
    ~Div() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
