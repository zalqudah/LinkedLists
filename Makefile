CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

all: SingleLinked DoubleLinked

SingleLinked: $(OBJECTS) testSingle.cpp SingleLinked.cpp Node.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

DoubleLinked: $(OBJECTS) testDouble.cpp DoubleLinked.cpp Node.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o core main
