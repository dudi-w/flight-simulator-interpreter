#ifndef PARSER_EXCEPTIONS_HPP
#define PARSER_EXCEPTIONS_HPP

#include <string>

#include "../base_exception.hpp"

namespace fp { 
namespace parser {

class ParserError : public BaseException {
public:
    inline ParserError(size_t row, size_t column);
    inline ParserError(size_t row, size_t column, std::string msg);

    inline size_t row();
    inline size_t column();
private:
    size_t m_row;
    size_t m_column;
};

inline ParserError::ParserError(size_t row, size_t column)
:BaseException("Parser failed in line " + std::to_string(row) + " column " + std::to_string(column))
,m_row(row)
,m_column(column)
{}

inline ParserError::ParserError(size_t row, size_t column, std::string msg)
:BaseException("Parser failed in line " + std::to_string(row) + " column " + std::to_string(column) + "message: \n\t" + msg)
,m_row(row)
,m_column(column)
{}

inline size_t ParserError::row()
{
    return m_row;
}

inline size_t ParserError::column()
{
    return m_column;
}


} // namespace parser
} // namespace fp

#endif
