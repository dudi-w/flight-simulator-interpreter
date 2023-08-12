#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include "token_enum.hpp"

namespace fgi {
namespace lexer {

class Token {
public:
    Token(Token const& other) = delete;
    Token& operator=(Token const& other) = delete;
    explicit Token(
        TokenType type,
        std::string str,
        size_t row,
        size_t column
    );

    TokenType type() const;
    std::string const& str() const;
    size_t row() const;
    size_t column() const;

private:
    TokenType m_type;
    std::string m_str;
    size_t m_row;
    size_t m_column;
};

} // namespace lexer
} // namespace fgi
#endif
