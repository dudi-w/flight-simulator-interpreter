#ifndef PARSER_HPP
#define PARSER_HPP

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

class Parser {
    using TokensItr = std::vector<lexer::Token>::const_iterator;
public:
    Parser(Parser const& other) = delete;
    Parser& operator=(Parser const& other) = delete;
    Parser() = default;

    std::unique_ptr<Command> parse(std::vector<lexer::Token> const& tokens) const;

private:
    static std::unique_ptr<Command> parse(TokensItr&, TokensItr);
    static std::unique_ptr<Expression> build_expression(TokensItr& it, TokensItr end);

    // commands builders
    static std::unique_ptr<Command> codeBlock_builder(TokensItr& it, TokensItr end);
    static std::unique_ptr<Command> connect_builder(TokensItr& it, TokensItr end);
    static std::unique_ptr<Command> openDataServer_builder(TokensItr& it, TokensItr end);
    static std::unique_ptr<Command> print_builder(TokensItr& it, TokensItr end);
    static std::unique_ptr<Command> sleep_builder(TokensItr& it, TokensItr end);
    static std::unique_ptr<Command> var_heandler(TokensItr& it, TokensItr end);
    static std::unique_ptr<Command> while_builder(TokensItr& it, TokensItr end);



    using BuilderFunc = std::unique_ptr<Command>(*)(TokensItr&, TokensItr);
    static inline std::unordered_map<lexer::TokenType, BuilderFunc> m_buildersMap = {
        {lexer::TokenType::Connect, connect_builder},
        {lexer::TokenType::OpenDataServer, openDataServer_builder},
        {lexer::TokenType::Print, print_builder},
        {lexer::TokenType::Print, sleep_builder},
        {lexer::TokenType::Print, var_heandler},
        {lexer::TokenType::Print, while_builder},
        {lexer::TokenType::LeftCurlyBracket, codeBlock_builder}
    };
};

} // namespace parser
} // namespace fgi
#endif