#ifndef SUB_HPP
#define SUB_HPP

#include <memory>

#include "expression.hpp"

namespace fgi { // namespace flight gear

class Sub : public IExpression
{
public:
    explicit Sub(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second);
    Sub(Sub const& other) = default;
    Sub& operator=(Sub const& other) = default;
    ~Sub() = default;

    float get_value() const override;

private:
    std::shared_ptr<IExpression> m_first;
    std::shared_ptr<IExpression> m_second;
};

} //namespace

#endif