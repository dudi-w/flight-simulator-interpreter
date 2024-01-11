add_library(larser 
    parser.cpp 
    expressionParser.cpp 
    commands_factory.cpp
)

target_include_directories(
    larser INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
    larser PRIVATE flightplan_compiler_flags lexer command_module expression)
