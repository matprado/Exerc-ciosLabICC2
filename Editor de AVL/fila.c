#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "avl.h"

struct fila{
	NODE* cabeca;
	NODE* fim;
	int tamanho;
};

struct no_{
	NO *item;
	NODE *proximo;
};

struct No{
	int item;
	NO *fesq;
	NO *fdir;
	int altura;
};

FILA *fila_criar(void){
	FILA *new = (FILA *)malloc(sizeof(FILA));
	if(new != NULL){		
		new->cabeca = (NODE *) malloc(sizeof(NODE));
		new->cabeca->proximo = NULL;
		new->fim = NULL;
		new->tamanho = 0;
	}
	return new;
}

void fila_apagar(FILA *F){
	NODE *aux, *apaga;
	if(F != NULL){
		aux = F->cabeca;
		do{
			apaga = aux;
			aux = aux->proximo;
			free(apaga);
		}while(aux != NULL);
		free(F);
	}
}

void fila_inserir(FILA *F, NO *item){
	NODE *novo;
	if(F != NULL){
	 	novo = (NODE *)malloc(sizeof(NODE));
	 	if(novo != NULL){
	 		novo->item = item;
	 		novo->proximo = NULL;
	 		if(fila_vazia(F)){
	 			F->cabeca->proximo = novo;
	 			F->fim = novo;
	 		}else{
	 			F->fim->proximo = novo;
	 			F->fim = novo; 	
			}
			F->tamanho++;
		}
	}
	//printf("%p\n", F->fim);
}

NO *fila_retirar(FILA *F){
	/*RETIRAR O PRIMEIRO E MOVER TODOS OS PŔOXIMOS UMA POSIÇÃO PARA TRÁS*/
	NO *item = NULL;
	NODE *aux;
	if(F != NULL && !fila_vazia(F)){
		item = F->cabeca->proximo->item;
		aux = F->cabeca->proximo;
		F->cabeca->proximo = F->cabeca->proximo->proximo;
		free(aux);
		F->tamanho--;	
	}
	return item;
}

int fila_vazia(FILA *F){
	return(F->tamanho == 0);
}
