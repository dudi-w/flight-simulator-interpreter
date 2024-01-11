add_library(environment 
    environment.cpp
    simulator.cpp
    simulatorTest.cpp
)

target_include_directories(
    environment INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(
    environment PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
    environment PUBLIC flightplan_compiler_flags communication_module variable)

target_link_libraries(
    environment PRIVATE nlohmann_json)