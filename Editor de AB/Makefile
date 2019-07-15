all: fila.o abb.o editor.o
	gcc -g fila.o abb.o editor.o -o editor -Wall

fila.o:
	gcc -g -c fila.c

abb.o:
	gcc -g -c abb.c

editor.o:
	gcc -g -c editor.c

clean:
	rm *.o editor

run:
	./editor

						