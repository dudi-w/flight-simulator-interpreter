#include <vector>
#include <string>

#include "lexer.hpp"
#include "token.hpp"

using fp::lexer::TokenType;
using fp::lexer::Token;

std::vector<std::string> extract_paths(std::vector<Token> const& tokens){
    std::vector<std::string> paths;
    auto[it, end] = std::pair{std::begin(tokens), std::end(tokens)-1};
    while (it < end)
    {
        if(it->type() == TokenType::Bind && (++it)->type() == TokenType::String){
            paths.push_back(it->str());
        }
        ++it;
    }
    return paths;
}
