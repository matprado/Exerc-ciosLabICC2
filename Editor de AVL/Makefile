all: fila.o avl.o editor.o
	gcc -g fila.o avl.o editor.o -o editor -Wall

fila.o:
	gcc -g -c fila.c

avl.o:
	gcc -g -c avl.c

editor.o:
	gcc -g -c editor.c

clean:
	rm *.o editor

run:
	./editor

