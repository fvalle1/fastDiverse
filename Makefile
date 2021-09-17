CXX=g++
CFLAGS=-O3
LDFLAGS=
OBJECTS=reader.o fileReader.o monitor.o parallel_func.o
INCLUDE=-I. -Iinclude/ -I/usr/include/python3.9/
LIBS = -pthread
TARGETS = diversity.out 

all: $(TARGETS)

diversity.out: main.cpp $(OBJECTS)
	$(CXX) $(CFLAGS) $(INCLUDE) $(LIBS) $^ -o $@

%.o: src/%.cpp include/%.h	
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf *.out *.o *.so $(TARGETS)