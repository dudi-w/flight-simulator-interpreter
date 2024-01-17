#ifndef EXPRESSION_PARSER
#define EXPRESSION_PARSER

#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>

#include "../lexer/token.hpp"
#include "../expression/expression.hpp"
#include "../lexer/token_enum.hpp"
#include "../expression/add.hpp"
#include "../expression/literal.hpp"
#include "../expression/sub.hpp"
#include "../expression/great_operator.hpp"
#include "../expression/small_operator.hpp"
#include "../expression/mul.hpp"
#include "../expression/div.hpp"
#include "../expression/variable_expression.hpp"


namespace fp {
namespace parser
{

class ExpressionParser
{
public:
    using ResultPtr = std::unique_ptr<exp::IExpression>;
    using TokenIterator = std::vector<lexer::Token>::const_iterator;
    
    explicit ExpressionParser(std::vector<lexer::Token>::const_iterator start, std::vector<lexer::Token>::const_iterator end);
    ExpressionParser(ExpressionParser const& other) = default;
    ExpressionParser& operator=(ExpressionParser const& other) = default;

    std::pair<ResultPtr, TokenIterator> parse();

private:
    std::unique_ptr<exp::IExpression> parseAddSub() ;
    std::unique_ptr<exp::IExpression> parseMulDiv() ;
    std::unique_ptr<exp::IExpression> parseNumber() ;
    std::unique_ptr<exp::IExpression> parseComparison();
    bool IsAddSubOperator(lexer::TokenType type) const;
    bool IsMulDivOperator(lexer::TokenType type) const;
    bool IsLowGreatThen(lexer::TokenType type) const;

private:
    std::vector<lexer::Token>::const_iterator m_startToken;
    std::vector<lexer::Token>::const_iterator m_endToken;
    size_t m_row;
    int m_parenLevel;

    static inline std::unordered_map<lexer::TokenType, std::function<std::unique_ptr<exp::IExpression>(std::unique_ptr<exp::IExpression>, std::unique_ptr<exp::IExpression>)>> m_caseMap = { 
        {lexer::TokenType::Add, [](std::unique_ptr<exp::IExpression> left, std::unique_ptr<exp::IExpression> right) {
        return std::make_unique<exp::Add>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::Sub, [](std::unique_ptr<exp::IExpression> left, std::unique_ptr<exp::IExpression> right) {
        return std::make_unique<exp::Sub>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::LessThan, [](std::unique_ptr<exp::IExpression> left, std::unique_ptr<exp::IExpression> right) {
        return std::make_unique<exp::SmallOperator>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::GreatThen, [](std::unique_ptr<exp::IExpression> left, std::unique_ptr<exp::IExpression> right) {
        return std::make_unique<exp::GreatOperator>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::Mul, [](std::unique_ptr<exp::IExpression> left, std::unique_ptr<exp::IExpression> right) {
        return std::make_unique<exp::Mul>(std::move(left), std::move(right));
        }},
        {lexer::TokenType::Div, [](std::unique_ptr<exp::IExpression> left, std::unique_ptr<exp::IExpression> right) {
        return std::make_unique<exp::Div>(std::move(left), std::move(right));
        }}, 
    };
};

} // namespace fp

} // namespace parser

#endif