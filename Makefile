dev#nahum#variableCXX = g++
CC = $(CXX)

CXXFLAGS = -std=c++17 -Wall -pedantic
CXXFLAGS += -g3
CXXFLAGS += -Werror 


main : main.o  add.o  literal.o  sub.o  mul.o  div.o  great_operator.o  equle_operator.o  local_variable.o  bind_variable.o  variable_map.o  environment.o

main.o : main.cpp  expression.hpp  literal.hpp  add.hpp  sub.hpp  mul.hpp  div.hpp  great_operator.hpp  equle_operator.hpp  variable.hpp  local_variable.hpp  bind_variable.hpp  variable_map.hpp  environment.hpp
literal.o: expression.hpp  literal.hpp  literal.cpp
add.o : expression.hpp  add.hpp  add.cpp
sub.o: expression.hpp  sub.hpp  sub.cpp
mul.o: expression.hpp  mul.hpp  mul.cpp
div.o: expression.hpp  div.hpp  div.cpp
great_operator.o: expression.hpp  great_operator.hpp  great_operator.cpp
equle_operator.o: expression.hpp  equle_operator.hpp  equle_operator.cpp
local_variable.o: variable.hpp  local_variable.hpp  local_variable.cpp
bind_variable.o: variable.hpp  bind_variable.hpp  bind_variable.cpp
variable_map.o: variable_map.hpp  variable_map.cpp
environment.o: environment.hpp  environment.cpp

clean:
	$(RM) *.o ./main