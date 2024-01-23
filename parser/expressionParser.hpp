#ifndef EXPRESSION_PARSER
#define EXPRESSION_PARSER

#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>

#include "lexer/token.hpp"
#include "expression/expression.hpp"
#include "lexer/token_enum.hpp"
#include "expression/add.hpp"
#include "expression/literal.hpp"
#include "expression/sub.hpp"
#include "expression/great_equal_operator.hpp"
#include "expression/less_equal_operator.hpp"
#include "expression/great_operator.hpp"
#include "expression/small_operator.hpp"
#include "expression/equle_operator.hpp"
#include "expression/not_equal_operator.hpp"
#include "expression/mul.hpp"
#include "expression/div.hpp"
#include "expression/variable_expression.hpp"


namespace fp {
namespace parser
{

class ExpressionParser
{
public:
    using ExprPtr = std::unique_ptr<exp::IExpression>;
    using TokenIterator = std::vector<lexer::Token>::const_iterator;
    
    explicit ExpressionParser(std::vector<lexer::Token>::const_iterator start, std::vector<lexer::Token>::const_iterator end);
    ExpressionParser(ExpressionParser const& other) = default;
    ExpressionParser& operator=(ExpressionParser const& other) = default;

    std::pair<ExprPtr, TokenIterator> parse();

private:
    ExprPtr parseAddSub() ;
    ExprPtr parseMulDiv() ;
    ExprPtr parseNumber() ;
    ExprPtr parseComparison();
    bool IsAddSubOperator(lexer::TokenType type) const;
    bool IsMulDivOperator(lexer::TokenType type) const;
    bool IsComparison(lexer::TokenType type) const;

private:
    std::vector<lexer::Token>::const_iterator m_startToken;
    std::vector<lexer::Token>::const_iterator m_endToken;
    size_t m_row;
    int m_parenLevel;

    static inline const std::unordered_map<lexer::TokenType, std::function<ExprPtr(ExprPtr, ExprPtr)>> m_caseMap = { 
        {lexer::TokenType::Add, [](ExprPtr left, ExprPtr right) {
        return std::make_unique<exp::Add>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::Sub, [](ExprPtr left, ExprPtr right) {
        return std::make_unique<exp::Sub>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::LessThan, [](ExprPtr left, ExprPtr right) {
        return std::make_unique<exp::LessOperator>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::GreatThen, [](ExprPtr left, ExprPtr right) {
        return std::make_unique<exp::GreatOperator>(std::move(left), std::move(right));
        }},    
        {lexer::TokenType::LessEqualThan, [](ExprPtr left, ExprPtr right) {
        return std::make_unique<exp::LessEqualOperator>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::GreatEqualThen, [](ExprPtr left, ExprPtr right) {
        return std::make_unique<exp::GreatEqualOperator>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::Equal, [](ExprPtr left, ExprPtr right) {
        return std::make_unique<exp::EquleOperator>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::NotEqual, [](ExprPtr left, ExprPtr right) {
        return std::make_unique<exp::NotEqualOperator>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::Mul, [](ExprPtr left, ExprPtr right) {
        return std::make_unique<exp::Mul>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::Div, [](ExprPtr left, ExprPtr right) {
        return std::make_unique<exp::Div>(std::move(left), std::move(right));
        }}, 
    };
};

} // namespace fp

} // namespace parser

#endif