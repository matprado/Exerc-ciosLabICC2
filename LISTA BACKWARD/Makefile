all: lista.o backward.o
	gcc -g lista.o backward.o -o back

lista.o:
	gcc -g -c lista.c

backward.o:
	gcc -g -c backward.c

clean:
	rm *.o back

run:
	./back

			