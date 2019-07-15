#ifndef FILA_H
#define FILA_H
#include "monomio.h"

#define MAX 10
typedef struct fila FILA;

FILA *fila_criar(void);
void fila_apagar(FILA *F);
void fila_inserir(FILA *F);
MON *fila_retirar(FILA *F);
int fila_vazia(FILA *F);
int fila_cheia(FILA *F);
void fila_copiar(FILA *orig, FILA *copia);

#endif