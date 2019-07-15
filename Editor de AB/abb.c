#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include "abb.h"

struct No_{
	int chave;
	NO *esq;
	NO *dir;
};

struct abb{
	NO *raiz;
};

ABB *arv_criar(void){
	ABB *T = (ABB *) malloc(sizeof(ABB));
	if(T != NULL){
		T->raiz = NULL;
		//T->prof = -1;
	}
	return (T);
}

int abb_inserir(ABB *T, int chave){
	if(T == NULL)
		return 0;
	if(T->raiz == NULL){
		T->raiz = (NO *) malloc(sizeof(NO));
		if(T->raiz != NULL){
			T->raiz->chave = chave;
			T->raiz->esq = NULL;
			T->raiz->dir = NULL;
			return 1;
		}
	}else return(abb_inserir_no(T->raiz, chave));
}

NO *abb_inserir_filho(int filho, NO *no, int chave){
	NO *pnovo = (NO *) malloc(sizeof (NO));
	if(pnovo != NULL){
		pnovo->dir = NULL;
		pnovo->esq = NULL;
		pnovo->chave = chave;
		if(filho == 0)
			no->esq = pnovo;
		else
			no->dir = pnovo;
	}
	return pnovo;
}

int abb_inserir_no(NO *raiz, int chave){
	if(chave < raiz->chave){
		if(raiz->esq != NULL)
			return(abb_inserir_no(raiz->esq, chave));
		else
			return (abb_inserir_filho(0, raiz, chave) != NULL);
	}else{
		if(chave > raiz->chave){
			if(raiz->dir != NULL)
				return abb_inserir_no(raiz->dir, chave);
			else
				return(abb_inserir_filho(1, raiz, chave) != NULL);
		}else
			return 0;
	}
}

int abb_busca(NO *raiz, int chave){
	if(raiz == NULL){
		return -404;
	}else{
		if(chave == raiz->chave){
			return (raiz->chave);
		}
		else{
			if(chave < raiz->chave)
				return (abb_busca(raiz->esq, chave));
			else
				return (abb_busca(raiz->dir, chave));
		}
	}
}

void troca_max_esq(NO *troca, NO *rem, NO *ant){
	if(troca->dir != NULL){
		return troca_max_esq(troca->dir, rem, troca);
	}
	if(rem == ant)
		ant->esq = troca->esq;
	else
		ant->dir = troca->esq;
	rem->chave = troca->chave;
	free(troca);
	troca = NULL;
}

void troca_max_dir(NO *troca, NO *rem, NO *ant){
	if(troca->esq != NULL){
		return troca_max_dir(troca->esq, rem, troca);
	}
	if(rem == ant)
		ant->dir = troca->dir;
	else
		ant->esq = troca->dir;
	rem->chave = troca->chave;
	free(troca);
	troca = NULL;
}


int abb_remover_aux(NO *raiz, NO *rem, NO *ant, int chave){
/*abb_remover_aux(T->raiz, T->raiz, NULL, chave);*/
	NO *prox;
	if(rem == NULL)
		return 0;
	if(chave < rem->chave)
		return abb_remover_aux(raiz, rem->esq, rem, chave);
	else{
		if(chave > rem->chave)
			return abb_remover_aux(raiz, rem->dir, rem, chave);
		else{
			/*Caso 2: há apenas um dos filhos*/
			if(rem->esq == NULL || rem->dir == NULL){
				if(rem->esq == NULL)
					prox = rem->dir;
				else
					prox = rem->esq;
				if(ant == NULL)
					raiz = prox;
				else{
				/*rem eh filho esq ou dir de ant?*/
					if(rem == ant->esq)
						ant->esq = prox;
					else
						ant->dir = prox;
				}
				free(rem); rem = NULL;}
			else{ /*Caso 3: há ambos os filhos*/
				//troca_max_esq(rem->esq, rem, rem);
				troca_max_dir(rem->dir, rem, rem);
			}
			return 1;
		}
	}
}

void pre_ordem(NO *raiz){
	if(raiz != NULL){
		printf(" %d", raiz->chave);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}

void em_ordem(NO *raiz){
	if(raiz != NULL){
		em_ordem(raiz->esq);
		printf(" %d", raiz->chave);	
		em_ordem(raiz->dir);
	}
}

void pos_ordem(NO *raiz){
	if(raiz != NULL){
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);	
		printf(" %d", raiz->chave);
	}
}

void imprimir_largura(NO *raiz){
	FILA *F = fila_criar();	
	fila_inserir(F, raiz);
	//fila_imprimir(F);
	NO *aux;
	while(!fila_vazia(F)){
		aux = fila_retirar(F);
		printf(" %d", aux->chave);
		if(aux->esq != NULL) fila_inserir(F, aux->esq);
		if(aux->dir != NULL) fila_inserir(F, aux->dir);
	}
}

NO *ABB_raiz(ABB *T){
	return T->raiz;
}

int chave_item(NO *i){
	return i->chave;
}