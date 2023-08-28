#ifndef ADD_HPP
#define ADD_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plain

class Add : public IExpression
{
public:
    explicit Add(std::shared_ptr<IExpression> const& first, std::shared_ptr<IExpression> const& second);
    Add(Add const& other) = default;
    Add& operator=(Add const& other) = default;
    ~Add() = default;

    float get_value() const override;

private:
    std::shared_ptr<IExpression> m_first;
    std::shared_ptr<IExpression> m_second;
};

} //namespace fp

#endif
