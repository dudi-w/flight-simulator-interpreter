#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

namespace fp {

class Expression
{
public:
    virtual ~Expression() = default;
    
    virtual float get() = 0;
};

}// namespace fp

#endif
