add_library(command_module
    src/allocationLocalVarCommand.cpp   src/codeBlockCommand.cpp       src/printExpCommand.cpp     src/whileCommand.cpp
    src/allocationRemoteVarCommand.cpp  src/connectCommand.cpp         src/printStringCommand.cpp
    src/assignmentCommand.cpp           src/openDataServerCommand.cpp  src/sleepCommand.cpp
    
)

target_include_directories(
    command_module INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/includes)

target_include_directories(
    command_module PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)

target_link_libraries(
        command_module PRIVATE environment variable expression)
target_link_libraries(
    command_module PRIVATE flightplan_compiler_flags)
