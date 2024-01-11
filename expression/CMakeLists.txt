add_library(expression 
    add.cpp
    div.cpp
    equle_operator.cpp
    great_operator.cpp
    literal.cpp
    mul.cpp
    small_operator.cpp
    sub.cpp
    variable_expression.cpp
)

target_include_directories(
    expression INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


target_include_directories(
    expression PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    
target_link_libraries(
    expression PRIVATE flightplan_compiler_flags variable environment)
