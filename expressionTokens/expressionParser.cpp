#include <unordered_map>
#include <functional>
#include <stdexcept>
#include <iostream>

#include "expressionParser.hpp"

using namespace fp;
using namespace parser;

using ResultPtr = std::shared_ptr<IExpression>;
using TokenIterator = std::vector<lexer::Token>::const_iterator;

ExpressionParser::ExpressionParser(std::vector<lexer::Token>::const_iterator start, std::vector<lexer::Token>::const_iterator end)
: m_startToken(start)
, m_endToken(end)
, m_row(start->row())
, m_parenLevel(0)
{}

bool ExpressionParser::IsAddSubOperator(lexer::TokenType type) const {
    return (type == lexer::TokenType::Add ||
            type == lexer::TokenType::Sub );
}

bool ExpressionParser::IsMulDivOperator(lexer::TokenType type) const {
    return (type == lexer::TokenType::Mul || 
            type == lexer::TokenType::Div);
}

bool ExpressionParser::IsLowGreatThen(lexer::TokenType type) const {
    return (type == lexer::TokenType::GreatThen || 
            type == lexer::TokenType::LowThen);
}


std::pair<ResultPtr, TokenIterator> ExpressionParser::parse() {
    if (m_startToken->type() != lexer::TokenType::Number &&
        m_startToken->type() != lexer::TokenType::LeftBracket &&
        m_startToken->type() != lexer::TokenType::Name &&
        m_startToken->type() != lexer::TokenType::Sub) {
        throw std::runtime_error("Invalid expression: Operator cannot be the first character");
    }
    return {parseComparison(), m_startToken}; 
}

std::shared_ptr<IExpression> ExpressionParser::parseComparison() {
    std::shared_ptr<IExpression> left = parseAddSub();
    lexer::TokenType prevOp = lexer::TokenType::Add; 

    while (IsLowGreatThen(m_startToken->type())) {
        lexer::TokenType op = m_startToken->type();
        
        if (prevOp == lexer::TokenType::LowThen || prevOp == lexer::TokenType::GreatThen) {
            throw std::runtime_error("Consecutive comparison operators are not allowed.");
        }

        prevOp = op;
        ++m_startToken;

        std::shared_ptr<IExpression> right = parseAddSub();

        auto it = m_caseMap.find(op);
        if (it != m_caseMap.end()) {
            left = it->second(left, right);
        } else {
            throw std::runtime_error("No action defined for the given operator type.");
        }
    }

    return left;
}

std::shared_ptr<IExpression> ExpressionParser::parseAddSub() {
    std::shared_ptr<IExpression> left = parseMulDiv();

    while ( IsAddSubOperator(m_startToken->type()) ) {
        lexer::TokenType op = m_startToken->type();
        ++m_startToken;
        std::shared_ptr<IExpression> right = parseMulDiv();

        auto it = m_caseMap.find(op);
        if (it != m_caseMap.end()) {
            left = it->second(left, right);
        } else {
            throw std::runtime_error("No action defined for the given operator type.");
        }
    }

    return left;
}

std::shared_ptr<IExpression> ExpressionParser::parseMulDiv() {
    std::shared_ptr<IExpression> left = parseNumber();

    while (IsMulDivOperator(m_startToken->type())) {
        lexer::TokenType op = m_startToken->type();
        ++m_startToken;
        std::shared_ptr<IExpression> right = parseNumber();

        auto it = m_caseMap.find(op);
        if (it != m_caseMap.end()) {
            left = it->second(left, right);
        } else {
            throw std::runtime_error("No action defined for the given operator type.");
        }
    }

    return left;
}

std::shared_ptr<IExpression> ExpressionParser::parseNumber() 
{

    if (m_startToken == m_endToken) {
        throw std::runtime_error("Unexpected end of input.");
    }
    
    std::shared_ptr<IExpression> result;

    if (m_startToken->type() == lexer::TokenType::Sub) {
        ++m_startToken;
        std::shared_ptr<Literal> left = std::make_shared<Literal>("0");
        std::shared_ptr<IExpression> right = parseNumber();
        result = std::make_shared<Sub>(left, right);
        ++m_startToken;
        return result;
    }

    if (m_startToken->type() == lexer::TokenType::LeftBracket) {
        ++m_parenLevel;
        ++m_startToken;
        std::shared_ptr<IExpression> result = parseAddSub();

        if (m_startToken == m_endToken || m_startToken->type() != lexer::TokenType::RightBracket) {
            throw std::runtime_error("Expected closing parenthesis.");
        }

        --m_parenLevel;
        ++m_startToken;
        return result;
    }

    if (m_startToken->type() == lexer::TokenType::Number) {
        result = std::make_shared<Literal>(m_startToken->str());

    } else if (m_startToken->type() == lexer::TokenType::Name) {
        result = std::make_shared<VariableExpression>(m_startToken->str());
    }

    ++m_startToken;
    return result;
}