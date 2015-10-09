test: libadd.a test.o
	g++ test.o -L. -ladd -o test
add.o: add.cpp
	g++ -c add.cpp
libadd.a: add.o
	ar rcs libadd.a add.o
test.o: test.cpp
	g++ -c test.cpp
clean: 
	rm -f add.o test.o test libadd.a

