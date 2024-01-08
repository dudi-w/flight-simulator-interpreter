#include "environment.hpp"
#include "../variable/local_variable.hpp"
#include "../variable/remote_variable.hpp"

using env = fp::env::Environment;

int main(){
    env::simulatorControl().set_server_port(1234);
    env::simulatorControl().set_server_update_per_second(20);
    env::simulatorControl().set_simulator_host("127.0.0.1");
    env::simulatorControl().set_simulator_port(5400);
    
    std::this_thread::sleep_for(std::chrono::seconds(30));

    env::insert_to_map("warp",std::make_unique<fp::var::RemoteVariable>("/sim/time/warp"));
    env::getDataMap().insert("/sim/time/warp");
    env::insert_to_map("abc",std::make_unique<fp::var::LocalVariable>());
    env::set_variable_value("abc",1.2f);
    std::cout<<"\033[1;33mabc = "<<env::get_variable_value("abc")<<"\033[0m"<<std::endl;
    std::cout<<"\033[1;35mwarp = "<<env::get_variable_value("warp")<<"\033[0m"<<std::endl;
    env::set_variable_value("warp",0.3f);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<"\033[1;35mwarp = "<<env::get_variable_value("warp")<<"\033[0m"<<std::endl;
    return EXIT_SUCCESS;
}
