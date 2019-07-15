all: derivada_e_tangente.o fila.o monomio.o
	gcc -g monomio.o fila.o derivada_e_tangente.o -o at -Wall -lm

derivada_e_tangente.o:
	gcc -g -c derivada_e_tangente.c

fila.o:
	gcc -g -c fila.c

monomio.o:
	gcc -g -c monomio.c

clean:
	rm *.o at			

run:
	./at
	