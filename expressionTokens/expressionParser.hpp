#ifndef EXPRESSION_PARSER
#define EXPRESSION_PARSER

#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>

#include "../lexer/token.hpp"
#include "expression.hpp"
#include "../lexer/token_enum.hpp"
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
    explicit ExpressionParser(std::vector<lexer::Token>::const_iterator start, std::vector<lexer::Token>::const_iterator end);
    ExpressionParser(ExpressionParser const& other) = default;
    ExpressionParser& operator=(ExpressionParser const& other) = default;

    std::shared_ptr<IExpression> parse();

private:
    std::shared_ptr<IExpression> parseAddSub() ;
    std::shared_ptr<IExpression> parseMulDiv() ;
    std::shared_ptr<IExpression> parseNumber() ;

private:
    std::vector<lexer::Token>::const_iterator m_startToken;
    std::vector<lexer::Token>::const_iterator m_endToken;
    size_t m_row;
    int m_parenLevel;

    static inline std::unordered_map<lexer::TokenType, std::function<std::shared_ptr<IExpression>(std::shared_ptr<IExpression>, std::shared_ptr<IExpression>)>> m_caseMap = { 
        {lexer::TokenType::Add, [](std::shared_ptr<IExpression> left, std::shared_ptr<IExpression> right) {
        return std::make_shared<Add>(left, right);
        }},
        {lexer::TokenType::Sub, [](std::shared_ptr<IExpression> left, std::shared_ptr<IExpression> right) {
        return std::make_shared<Sub>(left, right);
        }},
        {lexer::TokenType::LowThen, [](std::shared_ptr<IExpression> left, std::shared_ptr<IExpression> right) {
        return std::make_shared<SmallOperator>(left, right);
        }},
        {lexer::TokenType::GreatThen, [](std::shared_ptr<IExpression> left, std::shared_ptr<IExpression> right) {
        return std::make_shared<GreatOperator>(left, right);
        }},
        {lexer::TokenType::Mul, [](std::shared_ptr<IExpression> left, std::shared_ptr<IExpression> right) {
        return std::make_shared<Mul>(left, right);
        }},
        {lexer::TokenType::Div, [](std::shared_ptr<IExpression> left, std::shared_ptr<IExpression> right) {
        return std::make_shared<Div>(left, right);
        }},
    
       
    };

};

} // namespace fp

} // namespace parser

#endif