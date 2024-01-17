#include  <cctype>
#include <regex>

#include "lexer.hpp"
#include "token.hpp"
#include "lexer_exceptions.hpp"

using namespace fp;
using namespace lexer;

std::vector<Token> Lexer::tokenize(std::string const &code) 
{
    State state(code);

    while(skipSpaces(state)){
        if(std::isdigit(*state.m_it)){
            numberHeandler(state);
        } else if (std::isalpha(*state.m_it)) {
            wordHeandler(state);
        } else if (symbol_chars.count(*state.m_it)) {
            operatorrHeandler(state);
        } else if (*state.m_it == '"') {
            stringHeandler(state);
        } else {
            throw LexerError(state.m_row, state.m_it - state.m_begin_of_row);
        }
    }
    return state.m_ret;
}

void Lexer::numberHeandler(State &state)
{
    static const std::regex r(R"(^\d+(\.\d+)?)");
    std::smatch sm;
    if(!regex_search(state.m_it, state.m_end, sm, r)){
        throw LexerError(state.m_row, state.m_it - state.m_begin_of_row, "That doesn't look like a valid number");
    }
    state.m_it = sm[0].second;  
    state.m_ret.emplace_back(
        TokenType::Number,
        sm[0].str(),
        state.m_row,
        state.m_it - state.m_begin_of_row
    );
}

bool Lexer::skipSpaces(State &state)
{
    while(state.m_it != state.m_end){
        if(*state.m_it == ' ' || *state.m_it == '\t'){
            ++state.m_it;
        } else if (*state.m_it == '\n'){
            ++state.m_it;
            ++state.m_row;
            state.m_begin_of_row = state.m_it;
        } else {
            return true;
        }
    }
    return false;
}

void Lexer::wordHeandler(State &state)
{
    static const std::regex r(R"(^[a-zA-Z_]+\w*)");
    std::smatch sm;
    if(!regex_search(state.m_it, state.m_end, sm, r)){
        throw LexerError(state.m_row, state.m_it - state.m_begin_of_row);
    }
    state.m_it = sm[0].second;  
    const std::string str_token = sm[0].str();

    TokenType type;
    if(auto symbol = known_symbols.find(str_token); symbol != known_symbols.end()){
        type = symbol->second;
    } else {
        type = TokenType::Name;
    }
    state.m_ret.emplace_back(
        type,
        std::move(str_token),
        state.m_row,
        state.m_it - state.m_begin_of_row
    );
}

void Lexer::operatorrHeandler(State &state)
{ 
    std::string str_token(state.m_it, state.m_it+1);
    TokenType type;
    if(auto match = known_symbols.find(str_token); match != known_symbols.end()){
        type = match->second;
    } else {
        throw LexerError(state.m_row, state.m_it - state.m_begin_of_row);
    }
    state.m_ret.emplace_back(
        type,
        std::move(str_token),
        state.m_row,
        state.m_it - state.m_begin_of_row
    );
    ++state.m_it;
}

void Lexer::stringHeandler(State &state) {
    static const std::regex r(R"(^\".*\")");
    std::smatch sm;
    if(!regex_search(state.m_it, state.m_end, sm, r)){
        throw LexerError(state.m_row, state.m_it - state.m_begin_of_row, "That doesn't look like a valid string");
    }

    state.m_ret.emplace_back(
        TokenType::String,
        std::string(sm[0].first+1, sm[0].second-1),
        state.m_row,
        state.m_it - state.m_begin_of_row
    );
    state.m_it = sm[0].second;
}

Lexer::State::State(std::string const &code)
:m_it(code.cbegin())
,m_end(code.cend())
,m_begin_of_row(m_it)
,m_row(0)
{}
