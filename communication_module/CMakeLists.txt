add_library(communication_module 
    src/netClient.cpp        src/TCPclient.cpp  src/TCPsocketFile.cpp
    src/simulatorServer.cpp  src/TCPserver.cpp
)

target_link_libraries(
    communication_module PUBLIC project_root_dir_include)

target_include_directories(
    communication_module PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/includes)
    
target_link_libraries(
    communication_module PRIVATE flightplan_compiler_flags)
