#include "token.hpp"

using namespace fgi;
using namespace lexer;

Token::Token(TokenType type, std::string str, size_t row, size_t column)
:m_type(type)
,m_str(str)
,m_row(row)
,m_column(column)
{}

TokenType fgi::lexer::Token::type() const
{
    return m_type;
}

std::string const &fgi::lexer::Token::str() const
{
    return m_str;
}

size_t fgi::lexer::Token::row() const
{
    return m_row;
}

size_t fgi::lexer::Token::column() const
{
    return m_column;
}
