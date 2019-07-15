all: ab.o bolas.o
	gcc -g ab.o bolas.o -o bolas -lm -Wall

ab.o:
	gcc -g -c ab.c -lm

bolas.o:
	gcc -g -c bolas.c

run:
	./bolas

clean:
	rm *.o bolas				