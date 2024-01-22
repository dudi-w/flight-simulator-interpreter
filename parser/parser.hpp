#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>

#include "lexer.hpp"
#include "token.hpp"
#include "token_enum.hpp"
#include "command.hpp"

namespace fp {
namespace parser {

class Parser {
    using TokensItr = std::vector<lexer::Token>::const_iterator;
public:
    Parser(Parser const& other) = delete;
    Parser& operator=(Parser const& other) = delete;
    Parser() = default;

    static std::unique_ptr<com::Command> parse(std::vector<lexer::Token> const& tokens);
    static std::unique_ptr<com::Command> parse(TokensItr it, TokensItr end);
};

} // namespace parser
} // namespace fg
#endif
