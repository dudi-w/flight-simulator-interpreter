#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.hpp"
#include "token.hpp"

int main()
{
    auto fs = std::ifstream("../flight_instructions.txt");
    std::stringstream ss;
    std::string c;
    ss << fs.rdbuf();
    c = ss.str();

    fgi::lexer::Lexer lexer;
    auto v = lexer.tokenize(c);
    for(auto const& t: v){
        std::cout 
            << "row: " << t.row()
            << ", clolumn: " << t.column()
            << ", type: " << static_cast<int>(t.type())
            << ", str: " << t.str()
            << std::endl;
    }

    
    return 0;
}
