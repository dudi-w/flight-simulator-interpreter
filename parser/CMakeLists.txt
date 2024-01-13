add_library(parser 
    parser.cpp 
    expressionParser.cpp 
    commands_factory.cpp
)

target_include_directories(
    parser INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
    parser PRIVATE flightplan_compiler_flags lexer command_module expression)
