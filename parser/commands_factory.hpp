#ifndef COMMANDS_FACTORY_HPP
#define COMMANDS_FACTORY_HPP

#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>

#include "I_lexer.hpp"
#include "token.hpp"
#include "token_enum.hpp"

#include "command.hpp"
#include "expression.hpp"

namespace fp {
namespace parser {

class CommandsFactory {
public:
    using TokensItr = std::vector<lexer::Token>::const_iterator;
    using ComPtr = std::unique_ptr<com::Command>;

    static std::pair<ComPtr, TokensItr> create(TokensItr it, TokensItr end);

private:
    static std::pair<std::unique_ptr<exp::IExpression>, TokensItr> build_expression(TokensItr it, TokensItr end);

    // commands builders
    using BuilderFunc = std::pair<ComPtr, TokensItr>(*)(TokensItr, TokensItr);
    static std::pair<ComPtr, TokensItr> curlyBracket_heandler(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> connect_builder(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> openDataServer_builder(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> print_builder(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> sleep_builder(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> var_heandler(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> assignment_builder(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> while_builder(TokensItr it, TokensItr end);
    
    static inline std::unordered_map<lexer::TokenType, BuilderFunc> m_buildersMap = {
        {lexer::TokenType::Connect, connect_builder},
        {lexer::TokenType::OpenDataServer, openDataServer_builder},
        {lexer::TokenType::Print, print_builder},
        {lexer::TokenType::Sleep, sleep_builder},
        {lexer::TokenType::Var, var_heandler},
        {lexer::TokenType::Name, assignment_builder},
        {lexer::TokenType::While, while_builder},
        {lexer::TokenType::LeftCurlyBracket, curlyBracket_heandler}
    };
};

} // namespace parser
} // namespace fgi
#endif
