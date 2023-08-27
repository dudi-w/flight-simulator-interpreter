#ifndef EXPRESSION_PARSER
#define EXPRESSION_PARSER

#include <vector>
#include <memory>

#include "./Lexer/token.hpp"
#include "expression.hpp"



namespace fgi {
    namespace Parser
    {

        class ExpressionParser
        {
        public:
            explicit ExpressionParser(std::vector<lexer::Token>::const_iterator start, std::vector<lexer::Token>::const_iterator end);
            ExpressionParser(ExpressionParser const& other) = default;
            ExpressionParser& operator=(ExpressionParser const& other) = default;

            std::shard_ptr<IExpression> parse();
        
        private:
            std::shared_ptr<IExpression> parseAddSub() const;
            std::shared_ptr<IExpression> parseMulDiv() const;
            std::shared_ptr<IExpression> parseNumber() const;
        
        private:
            std::vector<lexer::Token>::const_iterator m_startToken;
            std::vector<lexer::Token>::const_iterator m_endToken;
            size_t m_row;
            int m_parenLevel;

        };

    } // namespace fgi

} // namespace Parser

#endif