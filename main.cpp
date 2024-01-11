#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.hpp"
#include "token.hpp"

#include "parser.hpp"
#include "expressionParser.hpp"

int main1(int argc, char *argv[])
{
    if(argc != 2){
        std::cerr << "Usage: " << argv[0] << " " << "<path to flight instructions file>.";
        exit(-1);
    }
    auto fs = std::ifstream(argv[1]);
    std::stringstream ss;
    std::string c;
    ss << fs.rdbuf();
    c = ss.str();

    fp::lexer::Lexer lexer;
    auto v = lexer.tokenize(c);
    fp::parser::Parser parser;
    auto out = parser.parse(v);
    std::cout << "parser done" << std::endl;

    out->execute();
    std::cout << "done" << std::endl;

    // for(fp::lexer::Token const& t: v){
    //     std::cout 
    //         << "row: " << t.row()
    //         << ", clolumn: " << t.column()
    //         << ", type: " << static_cast<int>(t.type())
    //         << ", str: " << t.str()
    //         << std::endl;
    // }


    
    return 0;
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
