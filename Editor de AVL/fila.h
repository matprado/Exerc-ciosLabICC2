#ifndef FILA_H
#define FILA_H
#include "avl.h"

#define ERRO -404

typedef struct fila FILA;
typedef struct no_ NODE;
typedef struct No NO;


FILA *fila_criar(void);
void fila_apagar(FILA *F);
void fila_inserir(FILA *F, NO *item);
NO *fila_retirar(FILA *F);
int fila_vazia(FILA *F);

#endif