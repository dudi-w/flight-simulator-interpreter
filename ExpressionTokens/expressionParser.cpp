#include "expressionParser.hpp"

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
    while (m_startToken != m_endToken && (m_startToken->m_str == "+" || m_startToken->m_str == "-") && m_startToken->m_row == m_row) {
        std::string op = m_startToken->m_str;
        ++m_startToken;
        float right = parseMulDiv();
        if (op == "+") {
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
    while (m_startToken != m_endToken && (m_startToken->m_str == "*" || m_startToken->m_str == "/") && m_startToken->m_row == m_row) {
        std::string op = m_startToken->m_str;
        ++m_startToken;
        float right = parseNumber();
        if (op == "*") {
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

    if (m_startToken->m_str == "-") {
        ++m_startToken;
        return -parseNumber();
    }

    if (m_startToken->m_str == "(" && m_startToken->m_row == m_row) {
        ++m_parenLevel;
        ++m_startToken;
        float result = parseAddSub();
        if (m_startToken == m_endToken || m_startToken->m_str != ")" || m_startToken->m_row != m_row) {
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