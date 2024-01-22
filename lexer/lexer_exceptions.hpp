#ifndef LEXER_EXCEPTIONS_HPP
#define LEXER_EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

#include "base_exception.hpp"

namespace fp {
namespace lexer {

class LexerError : public BaseException {
public:
    inline LexerError(size_t row, size_t column);
    inline LexerError(size_t row, size_t column, std::string msg);

    inline size_t row();
    inline size_t column();
private:
    size_t m_row;
    size_t m_column;
};

inline LexerError::LexerError(size_t row, size_t column)
:BaseException("Lexar failed in line " + std::to_string(row) + " column " + std::to_string(column))
,m_row(row)
,m_column(column)
{}

inline LexerError::LexerError(size_t row, size_t column, std::string msg)
:BaseException("Lexar failed in line " + std::to_string(row) + " column " + std::to_string(column) + "message: \n\t" + msg)
,m_row(row)
,m_column(column)
{}

inline size_t LexerError::row()
{
    return m_row;
}

inline size_t LexerError::column()
{
    return m_column;
}


} // namespace lexer
} // namespace fp

#endif
