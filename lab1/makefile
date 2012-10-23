all: invert

invert: invert.o
	gcc -g -m32 -Wall -o invert invert.o
	rm -f *.o

invert.o: invert.c
	gcc -m32 -g -Wall -ansi -g -c -o invert.o invert.c

.PHONY : clean

clean:
	rm -f *.o
