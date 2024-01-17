#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "I_lexer.hpp"
#include "token.hpp"

namespace fp {
namespace lexer {

class Lexer : public Ilexer {
public:
    Lexer() = default;
    Lexer(Lexer const& other) = delete;
    Lexer& operator=(Lexer const& other) = delete;
    virtual ~Lexer() = default;

    std::vector<Token> tokenize(std::string const& code);

private: // internal state
    struct State{
        explicit State(std::string const& code);
        std::string::const_iterator m_it;
        std::string::const_iterator m_end;
        std::string::const_iterator m_begin_of_row;
        size_t m_row;
        std::vector<Token> m_ret;
    };

private:
    bool skipSpaces(State& state);
    void numberHeandler(State& state);
    void wordHeandler(State& state);
    void stringHeandler(State& state);
    void operatorrHeandler(State& state);

private: //static data
    inline static const std::unordered_map<std::string, TokenType> known_symbols = {
        {"while", TokenType::While},
        {"<", TokenType::LowThen},
        {">", TokenType::GreatThen},
        {"=", TokenType::Equal},
        {"!=", TokenType::NotEqual},
        {"+", TokenType::Add},
        {"-", TokenType::Sub},
        {"*", TokenType::Mul},
        {"/", TokenType::Div},
        {"(", TokenType::LeftBracket},
        {")", TokenType::RightBracket},
        {"{", TokenType::LeftCurlyBracket},
        {"}", TokenType::RightCurlyBracket},
        {"openDataServer", TokenType::OpenDataServer},
        {"connect", TokenType::Connect},
        {"print", TokenType::Print},
        {"sleep", TokenType::Sleep},
        {"var", TokenType::Var},
        {"bind", TokenType::Bind}
    };

    inline static const std::unordered_set<char> symbol_chars = {
        '+',
        '-',
        '*',
        '/',
        '=',
        '!',
        '>',
        '<',
        '(',
        ')',
        '{',
        '}'
    };
};

} // namespace lexer
} // namespace fp
#endif
