#include <unordered_map>
#include <functional>
#include <stdexcept>
#include <iostream>

#include "expressionParser.hpp"

using namespace fp;
using namespace parser;

using ResultPtr = std::unique_ptr<exp::IExpression>;
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

bool ExpressionParser::IsComparison(lexer::TokenType type) const {
    switch (type){
        case lexer::TokenType::GreatThen:
        case lexer::TokenType::GreatEqualThen:
        case lexer::TokenType::LessEqualThan:
        case lexer::TokenType::LessThan:
        case lexer::TokenType::Equal:
        case lexer::TokenType::NotEqual:
            return true;
        default:
            return false;
    }
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

std::unique_ptr<exp::IExpression> ExpressionParser::parseComparison() {
    std::unique_ptr<exp::IExpression> left = parseAddSub();
    lexer::TokenType prevOp = lexer::TokenType::Add; 

    while (IsComparison(m_startToken->type())) {
        lexer::TokenType op = m_startToken->type();
        
        if (IsComparison(prevOp)) {
            throw std::runtime_error("Consecutive comparison operators are not allowed.");
        }

        prevOp = op;
        ++m_startToken;

        std::unique_ptr<exp::IExpression> right = parseAddSub();

        auto it = m_caseMap.find(op);
        if (it != m_caseMap.end()) {
            left = it->second(std::move(left), std::move(right));
        } else {
            throw std::runtime_error("No action defined for the given operator type.");
        }
    }

    return left;
}

std::unique_ptr<exp::IExpression> ExpressionParser::parseAddSub() {
    std::unique_ptr<exp::IExpression> left = parseMulDiv();

    while ( IsAddSubOperator(m_startToken->type()) ) {
        lexer::TokenType op = m_startToken->type();
        ++m_startToken;
        std::unique_ptr<exp::IExpression> right = parseMulDiv();

        auto it = m_caseMap.find(op);
        if (it != m_caseMap.end()) {
            left = it->second(std::move(left), std::move(right));
        } else {
            throw std::runtime_error("No action defined for the given operator type.");
        }
    }

    return left;
}

std::unique_ptr<exp::IExpression> ExpressionParser::parseMulDiv() {
    std::unique_ptr<exp::IExpression> left = parseNumber();

    while (IsMulDivOperator(m_startToken->type())) {
        lexer::TokenType op = m_startToken->type();
        ++m_startToken;
        std::unique_ptr<exp::IExpression> right = parseNumber();

        auto it = m_caseMap.find(op);
        if (it != m_caseMap.end()) {
            left = it->second(std::move(left), std::move(right));
        } else {
            throw std::runtime_error("No action defined for the given operator type.");
        }
    }

    return left;
}

std::unique_ptr<exp::IExpression> ExpressionParser::parseNumber() 
{

    if (m_startToken == m_endToken) {
        throw std::runtime_error("Unexpected end of input.");
    }
    
    std::unique_ptr<exp::IExpression> result;

    if (m_startToken->type() == lexer::TokenType::Sub) {
        ++m_startToken;
        std::unique_ptr<exp::Literal> left = std::make_unique<exp::Literal>("0");
        std::unique_ptr<exp::IExpression> right = parseNumber();
        result = std::make_unique<exp::Sub>(std::move(left), std::move(right));
        return result;
    }

    if (m_startToken->type() == lexer::TokenType::LeftBracket) {
        ++m_parenLevel;
        ++m_startToken;
        result = parseAddSub();

        if (m_startToken == m_endToken || m_startToken->type() != lexer::TokenType::RightBracket) {
            throw std::runtime_error("Expected closing parenthesis.");
        }

        --m_parenLevel;
        ++m_startToken;
        return result;
    }

    if (m_startToken->type() == lexer::TokenType::Number) {
        result = std::make_unique<exp::Literal>(m_startToken->str());

    } else if (m_startToken->type() == lexer::TokenType::Name) {
        result = std::make_unique<exp::VariableExpression>(m_startToken->str());
    }

    ++m_startToken;
    return result;
}