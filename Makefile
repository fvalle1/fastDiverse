CXX=g++
CFLAGS=-O3
LDFLAGS=
DEPS=reader.cpp
INCLUDE=-I. -I/usr/include/python3.9/
LIBS = 
TARGETS = diversity.out 

all: $(TARGETS)

diversity.out: main.cpp $(DEPS)
	$(CXX) $(CFLAGS) $(INCLUDE) $^ -o $@

clean:
	rm -rf *.out *.o *.so $(TARGETS)