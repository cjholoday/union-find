SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)

tests: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o tests
	./tests


# debugging flags
CXXFLAGS = -std=c++11 -Wall -Werror -Wextra -pedantic -g

# compiler
CXX = g++

# make object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

clean:
	rm -f *.o tests

.PHONY: clean
