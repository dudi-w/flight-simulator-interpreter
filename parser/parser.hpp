#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory>

#include "../lexer/I_lexer.hpp"
#include "../lexer/token.hpp"
#include "../includs/command.hpp"


namespace fgi {
namespace parser {

class Parser {
public:
    Parser(Parser const& other) = delete;
    Parser& operator=(Parser const& other) = delete;
    Parser() = default;
};

} // namespace parser
} // namespace fgi
#endif