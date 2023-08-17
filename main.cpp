#include <iostream>
#include <fstream>

#include "literal.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mul.hpp"
#include "div.hpp"
#include "great_operator.hpp"
#include "equle_operator.hpp"
#include "local_variable.hpp"
#include "bind_variable.hpp"
#include "variable_map.hpp"
#include "environment.hpp"

using namespace fg;

int main()
{
    Environment& x = Environment::create_instance(std::cout);
    x.set_output_stream(std::cout);
    std::ofstream outputFile("output.txt");
    x.set_output_stream(outputFile);
    x.print("nahum halperyn");
    auto map = x.get_map();
    std::string num = "float";
    float f = 4.7;
    std::shared_ptr<IVariable> v = std::make_shared<LocalVariable>(num, f);
    std::string num_1 = "number";
    float f_1 = 8.98;
    std::shared_ptr<IVariable> v_1 = std::make_shared<LocalVariable>(num_1, f_1);
    map.insert(num, v);
    map.insert(num_1, v_1);
    auto map_1 = map.get_map();
    std::cout << map_1[num]->get_value() << "\n";
    std::cout << map_1[num_1]->get_value() << "\n";
    return 0;
}