#ifndef EXPRESSION_PARSER
#define EXPRESSION_PARSER

#include <vector>

#include "./Lexer/token.hpp"



namespace fgi
{
    namespace Parser
    {

        class ExpressionParser
        {
        public:
            explicit ExpressionParser(std::vector<lexer::Token>::const_iterator start, std::vector<lexer::Token>::const_iterator end);
            ExpressionParser(ExpressionParser const& other) = default;
            ExpressionParser& operator=(ExpressionParser const& other) = default;

            float parse();
        
        private:
            float parseAddSub();
            float parseMulDiv();
            float parseNumber();
        
        private:
            std::vector<lexer::Token>::const_iterator m_startToken;
            std::vector<lexer::Token>::const_iterator m_endToken;
            size_t m_row;
            int m_parenLevel;

        };

    } // namespace fgi

} // namespace Parser

#endif