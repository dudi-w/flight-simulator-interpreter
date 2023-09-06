#ifndef ADD_HPP
#define ADD_HPP

#include <memory>

#include "expression.hpp"

namespace fp { // namespace flight plan
namespace exp { // namespace exp

class Add : public IExpression
{
public:
    explicit Add(std::unique_ptr<IExpression> first, std::unique_ptr<IExpression> second);
    Add(Add const& other) = default;
    Add& operator=(Add const& other) = default;
    ~Add() = default;

    float get_value() const override;

private:
    std::unique_ptr<IExpression> m_first;
    std::unique_ptr<IExpression> m_second;
};

} //namespace exp
} //namespace fp

#endif
