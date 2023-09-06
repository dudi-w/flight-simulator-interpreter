#ifndef SUB_HPP
#define SUB_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plain

class Sub : public IExpression
{
public:
    explicit Sub(std::unique_ptr<IExpression>  first, std::unique_ptr<IExpression>  second);
    Sub(Sub const& other) = default;
    Sub& operator=(Sub const& other) = default;
    ~Sub() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace fp

#endif
