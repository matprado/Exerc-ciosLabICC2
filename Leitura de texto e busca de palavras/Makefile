all: word.o text.o busca.o
	gcc -g word.o text.o busca.o -o busca

word.o: word.c
	gcc -g -c word.c

text.o:	text.c
	gcc -g -c text.c

busca.o: busca.c
	gcc -g -c busca.c

clean: all
	rm *.o busca

run: all
	./busca