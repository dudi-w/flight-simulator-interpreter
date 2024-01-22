cmake_minimum_required(VERSION 3.15)

project(FlightPlan VERSION 1.0)

# specify the C++ standard
add_library(flightplan_compiler_flags INTERFACE)
target_compile_features(flightplan_compiler_flags INTERFACE cxx_std_20)
target_compile_options(flightplan_compiler_flags INTERFACE
  "-g3;-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused"
)

add_subdirectory(environment)
add_subdirectory(expression)
add_subdirectory(command_module)
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(variable)
add_subdirectory(communication_module)
# add the executable
add_executable(main main.cpp)

target_link_libraries(main PUBLIC flightplan_compiler_flags 
PUBLIC expression
PUBLIC communication_module
PUBLIC environment
PUBLIC variable
PUBLIC command_module
PUBLIC parser
PUBLIC lexer
)

add_library(project_root_dir_include INTERFACE)
target_include_directories(
  project_root_dir_include INTERFACE "$(PROJECT_SOURCE_DIR)")


include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)
