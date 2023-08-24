#ifndef COMMANDS_FACTORY_HPP
#define COMMANDS_FACTORY_HPP

#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>

#include "../lexer/I_lexer.hpp"
#include "../lexer/token.hpp"
#include "../lexer/token_enum.hpp"

#include "../includs/command.hpp"


namespace fp {
namespace parser {

class CommandsFactory {
public:
    using TokensItr = std::vector<lexer::Token>::const_iterator;
    using ComPtr = std::unique_ptr<Command>;

    static std::pair<ComPtr, TokensItr> create(TokensItr it, TokensItr end);

private:

    static std::unique_ptr<Expression> build_expression(TokensItr& it, TokensItr end);

    // commands builders
    static std::pair<ComPtr, TokensItr> codeBlock_builder(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> connect_builder(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> openDataServer_builder(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> print_builder(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> sleep_builder(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> var_heandler(TokensItr it, TokensItr end);
    static std::pair<ComPtr, TokensItr> while_builder(TokensItr it, TokensItr end);

    using BuilderFunc = std::pair<ComPtr, TokensItr>(*)(TokensItr, TokensItr);
    static inline std::unordered_map<lexer::TokenType, BuilderFunc> m_buildersMap = {
        {lexer::TokenType::Connect, connect_builder},
        {lexer::TokenType::OpenDataServer, openDataServer_builder},
        {lexer::TokenType::Print, print_builder},
        {lexer::TokenType::Sleep, sleep_builder},
        {lexer::TokenType::Var, var_heandler},
        {lexer::TokenType::While, while_builder},
        {lexer::TokenType::LeftCurlyBracket, codeBlock_builder}
    };
};

} // namespace parser
} // namespace fgi
#endif
