#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include "lexer.hpp"
#include "token.hpp"

#include "parser.hpp"
#include "expressionParser.hpp"

int main1(int argc, char *argv[])
{
    std::stringstream ss;
    if(argc == 2){
        auto fs = std::ifstream(argv[1]);
        ss << fs.rdbuf();
    } else if(!isatty(STDIN_FILENO)){ // on shell pipe
        ss << std::cin.rdbuf();
    } else {
        std::cerr << "Usage: " << argv[0] << " " << "<path to flight instructions file>.";
        return EXIT_FAILURE;
    }
    const std::string code = ss.str();

    fp::lexer::Lexer lexer;
    auto tokens = lexer.tokenize(code);
    auto out = fp::parser::Parser::parse(tokens);

    out->execute();

    return EXIT_SUCCESS;
}

#include "simulator.hpp"
int main2([[maybe_unused]]int argc, [[maybe_unused]]char *argv[]){
    fp::env::SimulatorControl sc;
    sc.set_server_port(1234);
    sc.set_server_update_per_second(20);
    sc.set_simulator_host("127.0.0.1");
    sc.set_simulator_port(5400);
    
    std::this_thread::sleep_for(std::chrono::seconds(30));
    sc.setValue("/sim/time/warp",0.3f);
    return 0;
}


int main3(int argc, char** argv)
{
	fp::lexer::Lexer lexer;

    std::vector<fp::lexer::Token> myVector = lexer.tokenize(
        argc == 2 ? argv[1] : "1 + 1/1 + 1/(1*2) + 1/(1*2*3) + 1/(1*2*3*4) + 1/(1*2*3*4*5)"
	);

    std::vector<fp::lexer::Token>::const_iterator beginIterator = myVector.cbegin();
    std::vector<fp::lexer::Token>::const_iterator endIterator = myVector.cend();
    fp::parser::ExpressionParser eParser(beginIterator, endIterator);
    std::unique_ptr<fp::exp::IExpression> expression = eParser.parse().first;
    std::cout << expression->get_value() << std::endl;
    return 0;
}

int main(int argc, char *argv[]){
    return main1(argc, argv);
}
