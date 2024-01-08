#include "simulator.hpp"

int main(){
    fp::env::SimulatorControl sc;
    sc.set_server_port(1234);
    sc.set_server_update_per_second(20);
    sc.set_simulator_host("127.0.0.1");
    sc.set_simulator_port(5400);
    
    std::this_thread::sleep_for(std::chrono::seconds(30));
    sc.setValue("/sim/time/warp",0.3f);
}