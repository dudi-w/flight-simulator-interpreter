#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include "token.hpp"

namespace fgi {
namespace lexer {

class Lexer {
public:
    Lexer(Lexer const& other) = delete;
    Lexer& operator=(Lexer const& other) = delete;
    Lexer() = default;

    std::vector<Token> tokenize(std::string const& code);


private:

};

} // namespace lexer
} // namespace fgi
#endif
