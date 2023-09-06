#ifndef EXPRESSION_PARSER
#define EXPRESSION_PARSER

#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>

#include "../../lexer/token.hpp"
#include "expression.hpp"
#include "../../lexer/token_enum.hpp"
#include "add.hpp"
#include "literal.hpp"
#include "sub.hpp"
#include "great_operator.hpp"
#include "small_operator.hpp"
#include "mull_operator.hpp"
#include "div.hpp"
#include "variable_expression.hpp"


namespace fp {
namespace parser
{

class ExpressionParser
{
public:
    using ResultPtr = std::unique_ptr<IExpression>;
    using TokenIterator = std::vector<lexer::Token>::const_iterator;
    
    explicit ExpressionParser(std::vector<lexer::Token>::const_iterator start, std::vector<lexer::Token>::const_iterator end);
    ExpressionParser(ExpressionParser const& other) = default;
    ExpressionParser& operator=(ExpressionParser const& other) = default;

    std::pair<ResultPtr, TokenIterator> parse();

private:
    std::unique_ptr<IExpression> parseAddSub() ;
    std::unique_ptr<IExpression> parseMulDiv() ;
    std::unique_ptr<IExpression> parseNumber() ;
    std::unique_ptr<IExpression> parseComparison();
    bool IsAddSubOperator(lexer::TokenType type) const;
    bool IsMulDivOperator(lexer::TokenType type) const;
    bool IsLowGreatThen(lexer::TokenType type) const;

private:
    std::vector<lexer::Token>::const_iterator m_startToken;
    std::vector<lexer::Token>::const_iterator m_endToken;
    size_t m_row;
    int m_parenLevel;

    static inline std::unordered_map<lexer::TokenType, std::function<std::unique_ptr<IExpression>(std::unique_ptr<IExpression>, std::unique_ptr<IExpression>)>> m_caseMap = { 
        {lexer::TokenType::Add, [](std::unique_ptr<IExpression> left, std::unique_ptr<IExpression> right) {
        return std::make_unique<Add>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::Sub, [](std::unique_ptr<IExpression> left, std::unique_ptr<IExpression> right) {
        return std::make_unique<Sub>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::LowThen, [](std::unique_ptr<IExpression> left, std::unique_ptr<IExpression> right) {
        return std::make_unique<SmallOperator>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::GreatThen, [](std::unique_ptr<IExpression> left, std::unique_ptr<IExpression> right) {
        return std::make_unique<GreatOperator>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::Mul, [](std::unique_ptr<IExpression> left, std::unique_ptr<IExpression> right) {
        return std::make_unique<Mul>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::Div, [](std::unique_ptr<IExpression> left, std::unique_ptr<IExpression> right) {
        return std::make_unique<Div>(std::move(left), std::move(right));
        }}, 
    };
};

} // namespace fp

} // namespace parser

#endif