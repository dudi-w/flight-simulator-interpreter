#ifndef ENUM_HPP
#define ENUM_HPP

namespace fp {
namespace lexer {

enum class TokenType : u_int8_t{
    Name,
    String,
    Number,
    While,
    LowThen,
    GreatThen,
    Equal,
    NotEqual,
    Add,
    Sub,
    Mul,
    Div,
    LeftBracket,
    RightBracket,
    LeftCurlyBracket,
    RightCurlyBracket,
    OpenDataServer,
    Connect,
    Print,
    Sleep,
    Var,
    Bind
};

} // namespace lexer
} // namespace fp

#endif