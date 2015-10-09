
TARGET=testdate student

all: $(TARGET)

.PHONY: all clean

testdate: date.o testdate.o
	g++ -o testdate date.o testdate.o

#student: student.o
#	g++ -c student.cpp

clean:
	rm -fr testdate *.o $(TARGET)

