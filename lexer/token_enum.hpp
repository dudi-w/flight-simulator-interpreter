namespace fgi {
namespace lexer {

enum class TokenType{
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
} // namespace fgi
