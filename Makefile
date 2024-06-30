CXX = g++
CXXFLAGS = -Wall  -std=c++11
INCLUDES = -I.
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = Demo

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)