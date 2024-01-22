add_library(lexer 
    lexer.cpp 
    token.cpp
)

target_include_directories(lexer 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(lexer 
    PRIVATE flightplan_compiler_flags project_root_dir_include)
