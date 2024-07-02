CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
INCLUDES = -I.
SRC = $(filter-out test.cpp, $(wildcard *.cpp))
TEST_SRC = $(filter-out Demo.cpp, $(wildcard *.cpp))
OBJ = $(SRC:.cpp=.o)
OBJ_TEST = $(TEST_SRC:.cpp=.o)
TARGET = main
TEST_TARGET = test

all: $(TEST_TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -lsfml-graphics -lsfml-window -lsfml-system -o $@ $^

$(TEST_TARGET): $(OBJ_TEST) doctest.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^
	./$(TEST_TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_TARGET) $(OBJ_TEST)
