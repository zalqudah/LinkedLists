CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

SingleLinked: $(OBJECTS) testSinle.cpp SingleLinked.cpp Node.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

DoubleLinked: $(OBJECTS) testDouble.cpp DoubleLinked.cpp Node.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o core main
