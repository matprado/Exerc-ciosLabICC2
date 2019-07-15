all: pilha.o paint.o
	gcc -g pilha.o paint.o -o paint

pilha.o:
	gcc -g -c pilha.c

paint.o:
	gcc -g -c paint.c

clean:
	rm *.o paint

run:
	./paint

					