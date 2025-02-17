#ifndef TOKEN_ENUM_HPP
#define TOKEN_ENUM_HPP

namespace fp {
namespace lexer {

enum class TokenType : u_int8_t{
    Name,
    String,
    Number,
    While,
    Assign,
    Equal,
    NotEqual,
    LessThan,
    LessEqualThan,
    GreatThen,
    GreatEqualThen,
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
