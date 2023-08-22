#include "expressionParser.hpp"
#include "./Lexer/token_enum.hpp"

using namespace fgi;
using namespace Parser;

ExpressionParser::ExpressionParser(std::vector<lexer::Token>::const_iterator start, std::vector<lexer::Token>::const_iterator end)
:m_startToken(start), m_endToken(end), m_row(start->m_row), m_parenLevel(0){}

float ExpressionParser::parse()
{
    return parseAddSub();
}

float ExpressionParser::parseAddSub()
{
    float left = parseMulDiv();
    while (m_startToken != m_endToken && (m_startToken->m_type == lexer::TokenType::Add || m_startToken->m_type == lexer::TokenType::Sub) && m_startToken->m_row == m_row) {
        lexer::TokenType op = m_startToken->m_type;
        ++m_startToken;
        float right = parseMulDiv();
        if (op == lexer::TokenType::Add) {
            left += right;
        } else {
            left -= right;
        }
    }
    return left;
}

float ExpressionParser::parseMulDiv()
{
    float left = parseNumber();
    while (m_startToken != m_endToken && (m_startToken->m_type == lexer::TokenType::Mul || m_startToken->m_type == lexer::TokenType::Div) && m_startToken->m_row == m_row) {
        lexer::TokenType op = m_startToken->m_type;
        ++m_startToken;
        float right = parseNumber();
        if (op == lexer::TokenType::Mul) {
            left *= right;
        } else {
            left /= right;
        }
    }
    return left;
}

float ExpressionParser::parseNumber()
{
    if (m_startToken == m_endToken) {
        throw std::runtime_error("Unexpected end of input.");
    }

    if (m_startToken->m_type == lexer::TokenType::Sub) {
        ++m_startToken;
        return -parseNumber();
    }

    if (m_startToken->m_type == lexer::TokenType::LeftBracket && m_startToken->m_row == m_row) {
        ++m_parenLevel;
        ++m_startToken;
        float result = parseAddSub();
        if (m_startToken == m_endToken || m_startToken->m_type != lexer::TokenType::RightBracket || m_startToken->m_row != m_row) {
            throw std::runtime_error("Expected opening parenthesis.");
        }
        --m_parenLevel;
        ++m_startToken;
        return result;
    }

    float number = std::stod(m_startToken->m_str);
    ++m_startToken;
    return number;
}