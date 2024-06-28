CXX = clang++
flags = -Wall -Wextra -g
OBJ = $(wildcard *.hpp) $(wildcard *.cpp)

all: Demo

Demo: main.o
	$(CXX) $(flags) -o $@ $^

main.o: main.cpp $(OBJ)
	$(CXX) $(flags) -c -o $@ main.cpp

clean:
	rm *.o Demo