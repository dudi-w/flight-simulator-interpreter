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

    static std::unique_ptr<Command> parse(std::vector<lexer::Token> const& tokens);
    static std::unique_ptr<Command> parse(TokensItr it, TokensItr end);
};

} // namespace parser
} // namespace fgi
#endif
