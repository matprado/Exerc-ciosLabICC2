all: imagens.o arvore_quaternaria.o
	gcc -g arvore_quaternaria.o imagens.o -o imagens -Wall -lm

imagens.o:
	gcc -g -c imagens.c

arvore_quaternaria.o:
	gcc -g -c arvore_quaternaria.c

clean:
	rm *.o imagens

run:
	./imagens			