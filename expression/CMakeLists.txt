add_library(expression 
    literal.cpp
    add.cpp
    div.cpp
    mul.cpp
    sub.cpp
    equle_operator.cpp
    not_equal_operator.cpp
    small_operator.cpp
    less_equal_operator.cpp
    great_operator.cpp
    great_equal_operator.cpp
    variable_expression.cpp
)

target_include_directories(
    expression INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


target_include_directories(
    expression PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    
target_link_libraries(
    expression PRIVATE flightplan_compiler_flags variable environment)
