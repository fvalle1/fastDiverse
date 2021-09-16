CXX=g++
CFLAGS=-O3
LDFLAGS=
DEPS=reader.cpp
INCLUDE=-I.

all: diversity.out

diversity.out: main.cpp $(DEPS)
	$(CXX) $(CFLAGS) $(INCLUDE) $^ -o $@

clean:
	rm -rf *.out *.o