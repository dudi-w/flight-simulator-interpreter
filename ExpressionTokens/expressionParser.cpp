#include <unordered_map>
#include <functional>

#include "expressionParser.hpp"

using namespace fp;
using namespace Parser;

ExpressionParser::ExpressionParser(std::vector<lexer::Token>::const_iterator start, std::vector<lexer::Token>::const_iterator end)
:m_startToken(start), m_endToken(end), m_row(start->m_row), m_parenLevel(0){}

std::shared_ptr<IExpression> ExpressionParser::parse()
{
    return parseAddSub();
}
    
std::shared_ptr<IExpression> ExpressionParser::parseAddSub() const
{
    std::shared_ptr<IExpression> result;
    std::shared_ptr<IExpression> left = parseMulDiv();
    while (m_startToken != m_endToken && (
    m_startToken->m_type == lexer::TokenType::Add ||
    m_startToken->m_type == lexer::TokenType::Sub || 
    m_startToken->m_type == lexer::TokenType::LowThen || 
    m_startToken->m_type == lexer::TokenType::GreatThen) && 
    m_startToken->m_row == m_row) {
        lexer::TokenType op = m_startToken->m_type;
        ++m_startToken;
        std::shared_ptr<IExpression> right = parseMulDiv();
        auto it = m_caseMap.find(op);
        if(it != m_caseMap.end()){
            result = it->second(left, right);
        }
        else {
        throw std::runtime_error("No action defined for the given op value");
        }
    }
    return result;
}

std::shared_ptr<IExpression> ExpressionParser::parseMulDiv() const
{
    std::shared_ptr<IExpression> result;
    std::shared_ptr<IExpression> left = parseNumber();
    while (m_startToken != m_endToken && (
        m_startToken->m_type == lexer::TokenType::Mul || 
        m_startToken->m_type == lexer::TokenType::Div) && 
        m_startToken->m_row == m_row) {
        lexer::TokenType op = m_startToken->m_type;
        ++m_startToken;
        std::shared_ptr<IExpression> right = parseNumber();
        auto it = m_caseMap.find(op);
        if(it != m_caseMap.end()){
            result = it->second(left, right);
        }
        else {
        throw std::runtime_error("No action defined for the given op value");
        }
    }
    return result;
}

std::shared_ptr<IExpression> ExpressionParser::parseNumber() const
{
    std::shared_ptr<IExpression> result;
    if (m_startToken == m_endToken) {
        throw std::runtime_error("Unexpected end of input.");
    }
    
    if (m_startToken->m_type == lexer::TokenType::Sub) {
        ++m_startToken;
        std::shared_ptr<Literal> left = std::make_shared<Literal>("0");
        std::shared_ptr<Literal> right = std::make_shared<Literal>(m_startToken->m_str);
        result = std::make_shared<Sub>(left, right);
        return result;
    }

    if (m_startToken->m_type == lexer::TokenType::LeftBracket && m_startToken->m_row == m_row) {
        ++m_parenLevel;
        ++m_startToken;
        std::shared_ptr<IExpression> result = parseAddSub();
        if (m_startToken == m_endToken || m_startToken->m_type != lexer::TokenType::RightBracket || m_startToken->m_row != m_row) {
            throw std::runtime_error("Expected opening parenthesis.");
        }
        --m_parenLevel;
        ++m_startToken;
        return result;
    }
    if (m_startToken->m_type == lexer::TokenType::Number) {
        result = std::make_shared<Literal>(m_startToken->m_str)
    } else if (m_startToken->m_type == lexer::TokenType::Var) {
        result = std::make_shared<VariableExpression>(m_startToken->m_str)
    }
    ++m_startToken;
    return result;
}