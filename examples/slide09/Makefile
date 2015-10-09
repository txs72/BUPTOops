TARGET=complex operator associate functor

all: $(TARGET)

.PHONY: all

complex: cm.o complex.o
	g++ -o complex cm.o complex.o

cm.o: cm.cpp
	g++ -c cm.cpp

complex.o: complex.cpp
	g++ -c complex.cpp

operator.o: operator.cpp
	g++ -c operator.cpp

operator: operator.o
	g++ -o operator operator.o

associate: associate.o
	g++ -o associate associate.o

functor: functor.o complex.o 
	g++ -o functor functor.o complex.o

clean:
	rm -fr *.o *.exe $(TARGET) 
