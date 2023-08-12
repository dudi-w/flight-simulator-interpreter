#include "lexer.hpp"

using namespace fgi;
using namespace lexer;

std::vector<Token> fgi::lexer::Lexer::tokenize(std::string const &code)
{
    size_t row = 0;
    size_t column = 0;
    auto it = std::begin(code);
    auto end = std::end(code);
    auto begin_of_row = it;

    std::vector<Token> ret;
    
    while(it < end){
        if(*it == '\n'){
            ++it;
            continue;
        } else if (*it == '\n'){
            ++it;
            ++row;
            begin_of_row = it;
            continue;
        }
        





    }


    
}