#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <string>
#include "token_enum.hpp"
namespace fgi {
namespace lexer {

struct Token {
    Token(Token const& other) = delete;
    Token& operator=(Token const& other) = delete;

    TokenType m_type;
    std::string m_str;
    size_t m_row;
    size_t m_column;
};

} // namespace lexer
} // namespace fgi
#endif
