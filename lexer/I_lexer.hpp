#ifndef I_lexer_HPP
#define I_lexer_HPP

#include <vector>
#include <string>

#include "token.hpp"

namespace fp {
namespace lexer {

class Ilexer {
public:
    virtual ~Ilexer() = default;
    virtual std::vector<Token> tokenize(std::string const& code) = 0;  
};

} // namespace lexer
} // namespace fp

#endif
