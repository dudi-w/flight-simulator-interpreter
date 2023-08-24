#include "expressionParser.hpp"
#include "./Lexer/token_enum.hpp"
#include "add.hpp"
#include "literal.hpp"
#include "sub.hpp"
#include "great_operator.hpp"
#include "small_operator.hpp"
#include "mull_operator.hpp"

using namespace fgi;
using namespace Parser;

ExpressionParser::ExpressionParser(std::vector<lexer::Token>::const_iterator start, std::vector<lexer::Token>::const_iterator end)
:m_startToken(start), m_endToken(end), m_row(start->m_row), m_parenLevel(0){}

std::shared_ptr<IExpression> ExpressionParser::parse()
{
    return parseAddSub();
}

std::shared_ptr<IExpression> ExpressionParser::parseAddSub()
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
        switch (op)
        {
        case lexer::TokenType::Add:
            result = std::make_shared<Add>(left, right);
            break;
        case lexer::TokenType::Sub:
            result = std::make_shared<Sub>(left, right);
            break;
        case lexer::TokenType::LowThen:
            result = std::make_shared<GreatOperator>(left, right);
            break;
        case lexer::TokenType::GreatThen:
            result = std::make_shared<SmallOperator>(left, right);
            break;
        default:
            break;
        }
        // if (op == lexer::TokenType::Add) {
        //     result = std::make_shared<Add>(left, right);
        // } else  if(op == lexer::TokenType::Sub) {
        //     result = std::make_shared<Sub>(left, right);
        // } else  if(op == lexer::TokenType::LowThen) {
        //     result = std::make_shared<Small_operator>(left, right);
        // } else  if(op == lexer::TokenType::GreatThen) {
        //     result = std::make_shared<Great_operator>(left, right);
        // }
    }
    return result;
}

std::shared_ptr<IExpression> ExpressionParser::parseMulDiv()
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
        if (op == lexer::TokenType::Mul) {
            result = std::make_shared<Mul>(left, right);
        } else {
            result = std::make_shared<Sub>(left, right);
        }
    }
    return result;
}

std::shared_ptr<IExpression> ExpressionParser::parseNumber()
{
    std::shared_ptr<IExpression> result;
    if (m_startToken == m_endToken) {
        throw std::runtime_error("Unexpected end of input.");
    }
    // TODO
    // if (m_startToken->m_type == lexer::TokenType::Sub) {
    //     ++m_startToken;
    //     return -parseNumber();
    // }

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