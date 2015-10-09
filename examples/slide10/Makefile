
TARGET=employ employee

all: $(TARGET)

.PHONY: all clean

employ: employ.o
	g++ -o employ employ.o

employee: employee.o
	g++ -o employee employee.o

clean:
	rm -fr employ employee *.o $(TARGET)

