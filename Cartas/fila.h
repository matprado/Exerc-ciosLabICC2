#ifndef FILA_H
#define FILA_H

#define ERRO -404
#define TIPO int
#define MAX 100
typedef struct fila FILA;

FILA *fila_criar(void);
void fila_apagar(FILA *F);
void fila_inserir(FILA *F, TIPO item);
TIPO fila_retirar(FILA *F);
int fila_vazia(FILA *F);
int fila_cheia(FILA *F);

#endif