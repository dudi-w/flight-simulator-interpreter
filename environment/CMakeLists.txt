add_library(environment 
    environment.cpp
    simulator.cpp
    simulatorTest.cpp
)

target_include_directories(
    environment INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(environment 
    PRIVATE flightplan_compiler_flags
    PUBLIC communication_module 
    PRIVATE variable
    PRIVATE nlohmann_json)
