#ifndef SUB_HPP
#define SUB_HPP

#include <memory>

#include "expression.hpp"

<<<<<<< HEAD
namespace fp { // namespace flight plan
namespace exp { // namespace exp
=======
namespace fg { // namespace flight gear
>>>>>>> 07320af (only expression files)

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

<<<<<<< HEAD
} //namespace exp
} //namespace fp
=======
} //namespace
>>>>>>> 07320af (only expression files)

#endif