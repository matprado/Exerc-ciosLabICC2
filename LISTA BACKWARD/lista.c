#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
	NO *inicio;
	NO *fim;
	int tam;
};

struct no{
	NO *proximo;
	NO *back;
	int chave;
	int tempo;
};

LISTA* lista_criar(void){
	LISTA *new = (LISTA *)malloc(sizeof(LISTA));
	if(new != NULL){		
		new->inicio = NULL;
		new->fim = NULL;
		new->tam = 0;
	}
	return new;
}

void lista_apagar(LISTA *L){
	if(L != NULL && !lista_vazia(L)){
   		NO *no = L->inicio,*aux;
    	while(no != L->fim){
       	 	aux = no;
       	 	no = no->proximo;
        	free(aux);
    	}
    	free(L->fim);
    	L->inicio = NULL;
    	L->fim = NULL;
		free(L);
		L = NULL;
	}
}

/*ITEM lista_buscar_item(LISTA *L, int chave){
	NO *aux = L->inicio;
	if(L != NULL){
		while(aux != NULL){
			if(aux->item == chave) return aux->item;
			aux = aux->proximo;
		}
	}
	return (ERRO);
}*/	

/*Retorna a poseção do nó na lista*/
NO *buscar_posicao(LISTA *L, int pos){
	int j = L->tam - pos; /* @@@<-      */
	int i=0;
	NO *aux;
	if(pos == 0){
		aux = NULL;
	}else{
		aux = L->inicio;
		while(i<j){	
			aux = aux->proximo;
			i++;
		}
	}	
	return aux;
}

int lista_inserir_fim(LISTA *L, int tempo, int chave, int j){
	NO *aux = NULL;
	if(L == NULL) return (ERRO);
	aux = (NO *) malloc(sizeof(NO));
	if(aux != NULL){
		aux->tempo = tempo;
		aux->chave = chave;
		aux->proximo = NULL;
		aux->back = buscar_posicao(L, j); /*deve retornar um nó da posição na lista (L->tam - j)*/
		/*CASO DE PRIMEIRO ELEMENTO*/
		if(lista_vazia(L)){
			L->inicio = aux;
			L->fim = aux;
			L->tam++;
		}else{ /*CASO DE QUALQUER ELEMENTO QUE NÃO O PRIMEIRO*/
			L->fim->proximo = aux;
			L->fim = aux;
			L->tam++;
		}
		return 1; /*SUCESSO*/
 	}
	return 0; /*FALHA*/
}

void atualizar_backs(LISTA *L, NO *aux_remocao){
	NO *aux = L->inicio;
	for(int i=1; i < L->tam; i++){
		if(aux->back == aux_remocao){
			aux->back = NULL;
		}
		aux = aux->proximo;
	}
}

int lista_remover_item(LISTA *L, int chave){
	NO *p = NULL, *aux = NULL;
	if(L != NULL && !lista_vazia(L)){
		p = L->inicio;
		while((p != NULL) && (p->chave != chave)){
			aux = p; /* aux_busca recebe o nó anterior de aux_remocao*/
			p = p->proximo;
		}
		if(p != NULL){
			if(p == L->inicio){ /*Exceção: chave no inicio*/
				L->inicio = p->proximo;
				p->proximo = NULL;
			}else{
				aux->proximo = p->proximo;
				p->proximo = NULL;
			}
			if(p == L->fim){ /* Se a chave está no último nó*/
				L->fim = aux;
			}
			atualizar_backs(L, p);
			L->tam--;
			free(p);
			return 1;
		}
	}
	return 0;
}

int posicao(LISTA *L, NO* x){
	NO *aux = L->inicio;
	for(int i=0; i < L->tam-1; i++){
		if(aux == x){
			return i;
		}
		aux = aux->proximo;
	}
	return -1;
}	

void lista_imprimir(LISTA *L){
	NO *aux = L->inicio;
	for(int i=0; i<L->tam; i++){
		printf("[%d,%d", aux->chave, aux->tempo);
		if(aux->back != NULL) printf(",%d", posicao(L, aux->back));
		printf("] ");
		aux = aux->proximo;
	}
	printf("\n");
}

int lista_vazia(LISTA *L){
	if(L != NULL && L->inicio == NULL) return 1;
 	return 0;
}

int lista_tamanho(LISTA *L){
	return (L != NULL ? L->tam : ERRO);	
}