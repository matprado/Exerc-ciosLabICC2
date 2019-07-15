#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct no{
	NO *anterior;
	int x;
	int y;
};

struct pilha{
	NO *topo;
	int quantidade;
};

int x_no(NO *n){
	return n->x;
}

int y_no(NO *n){
	return n->y;
}

PILHA *pilha_criar(){
	PILHA *P = (PILHA *) malloc(sizeof(PILHA));
	if(P != NULL){
		P->topo = NULL;
		P->quantidade = 0;
	}else P = NULL;
	return P;
}
	
void pilha_apagar(PILHA **P){
	NO *paux;
	if((*P) != NULL && !pilha_vazia(*P)){
		while((*P)->topo != NULL){
			paux = (*P)->topo;
			(*P)->topo = (*P)->topo->anterior;
			paux->anterior = NULL;
			free(paux);
		}
	}
	free(*P);
	*P = NULL;
}

int pilha_vazia(PILHA *P){
	return ((P != NULL) ? P->quantidade == 0 : ERRO);
}

NO *pilha_topo(PILHA *P){
	/*TIPO t = P->vet[quantidade-1];*/
	return ((P != NULL && !pilha_vazia(P)) ? P->topo : NULL);
}

int pilha_tamanho(PILHA *P){
	return ((P != NULL) ? P->quantidade : ERRO);
}

void pilha_empilhar(PILHA *P, int x, int y){
	NO *pnovo = (NO *) malloc(sizeof(NO));
	if(pnovo != NULL && P != NULL){
		pnovo->x = x;
		pnovo->y = y;
		pnovo->anterior = P->topo;
		P->topo = pnovo;
		P->quantidade++;
	}
}

NO *pilha_desempilhar(PILHA *P){
	//TIPO n;
	NO *pnovo;
	if(pnovo != NULL && !pilha_vazia(P)){
		pnovo = P->topo;
		P->topo = P->topo->anterior;
		pnovo->anterior = NULL;
		P->quantidade--;
	}else pnovo = NULL;
	return pnovo;
}	

int pilha_maior(PILHA *P1, PILHA *P2){
	return ((P1 != NULL && P2 != NULL) ? (P1->quantidade > P2->quantidade) : 0);
}

void imprime_topo(PILHA *P){
	printf("%d e %d\n", P->topo->x, P->topo->y);
}