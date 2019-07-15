#ifndef PILHA_H
#define PILHA_H

#define TIPO char
#define ERRO -1

typedef struct no NO;
typedef struct pilha PILHA;

PILHA *pilha_criar();	
void pilha_apagar(PILHA **P);
int pilha_vazia(PILHA *P);
NO *pilha_topo(PILHA *P);
int pilha_tamanho(PILHA *P);
void pilha_empilhar(PILHA *P, int x, int y);
NO *pilha_desempilhar(PILHA *P);		
int pilha_maior(PILHA *P1, PILHA *P2);
int x_no(NO *n);
int y_no(NO *n);
void imprime_topo(PILHA *P);

#endif