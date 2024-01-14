add_library(variable 
    local_variable.cpp  remote_variable.cpp  variable_map.cpp
)

target_include_directories(
    variable PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
    variable PRIVATE flightplan_compiler_flags communication_module)

target_link_libraries(
    variable PRIVATE nlohmann_json)

    