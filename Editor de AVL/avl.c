#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include "avl.h"

struct No{
	int item;
	NO *fesq;
	NO *fdir;
	int altura;
};

struct avl{
	NO *raiz;
	int profundidade;
};


AVL *avl_criar(void){
	AVL *arvore = (AVL *) malloc(sizeof (AVL));
	if(arvore != NULL){
		arvore->raiz = NULL;
		arvore->profundidade = -1;
	}
	return arvore;
}

void avl_apagar_aux(NO *raiz){
	if(raiz != NULL){
		avl_apagar_aux(raiz->fesq);
		avl_apagar_aux(raiz->fdir);
		free(raiz);
	}
}

void avl_apagar(AVL **arvore){
	avl_apagar_aux((*arvore)->raiz);
	free(*arvore);
	*arvore = NULL;
}

int avl_altura_no(NO* raiz){
	if(raiz == NULL){
		return -1;
	}else{
		return raiz->altura;
	}
}

NO *avl_cria_no(int item){
	NO *no = (NO *) malloc(sizeof (NO));
	if(no != NULL){
		no->altura = 0;
		no->fdir = NULL;
		no->fesq = NULL;
		no->item = item;
	}
	return no;
}

NO *rodar_direita(NO *a){
	NO *b = a->fesq;
	a->fesq = b->fdir;
	b->fdir = a;
	a->altura = max(avl_altura_no(a->fesq),avl_altura_no(a->fdir)) + 1;
	b->altura = max(avl_altura_no(b->fesq),	a->altura) + 1;
	return b;
}

NO *rodar_esquerda(NO *a){
	NO *b = a->fdir;
	a->fdir = b->fesq;
	b->fesq = a;
	a->altura = max(avl_altura_no(a->fesq),avl_altura_no(a->fdir)) + 1;
	b->altura = max(avl_altura_no(b->fdir),	a->altura) + 1;
	return b;
}

NO *rodar_esquerda_direita(NO *a){
	a->fesq = rodar_esquerda(a->fesq);
	return rodar_direita(a);
}

NO *rodar_direita_esquerda(NO *a){
	a->fdir = rodar_direita(a->fdir);
	return rodar_esquerda(a);
}

NO *avl_inserir_no(NO *raiz, int item){
	if(raiz == NULL){
		raiz = avl_cria_no(item);
	}else if(item > raiz->item){
		raiz->fdir = avl_inserir_no(raiz->fdir, item);
		if(avl_altura_no(raiz->fesq) - avl_altura_no(raiz->fdir) == -2){
			if(item > raiz->fdir->item){
				raiz = rodar_esquerda(raiz);
			}else{
				raiz = rodar_direita_esquerda(raiz);
			}
		}
	}else if(item < raiz->item){
		raiz->fesq = avl_inserir_no(raiz->fesq, item);
		if(avl_altura_no(raiz->fesq) - avl_altura_no(raiz->fdir) == 2){
			if(item < raiz->fesq->item){
				raiz = rodar_direita(raiz);
			}else{
				raiz = rodar_esquerda_direita(raiz);
			}
		}
	}
	raiz->altura = max(avl_altura_no(raiz->fesq),avl_altura_no(raiz->fdir)) + 1;
	return raiz;
}

int avl_inserir(AVL *arvore, int item){
	if(esta_na_avl(arvore->raiz, item)) return 0;
	return ((arvore->raiz = avl_inserir_no(arvore->raiz, item)) != NULL);
}

void pre_ordem(NO *raiz){
	if(raiz != NULL){
		printf(" %d", raiz->item);
		pre_ordem(raiz->fesq);
		pre_ordem(raiz->fdir);
	}
}

void em_ordem(NO *raiz){
	if(raiz != NULL){
		em_ordem(raiz->fesq);
		printf(" %d", raiz->item);	
		em_ordem(raiz->fdir);
	}
}

void pos_ordem(NO *raiz){
	if(raiz != NULL){
		pos_ordem(raiz->fesq);
		pos_ordem(raiz->fdir);	
		printf(" %d", raiz->item);
	}
}

void imprimir_largura(NO *raiz){
	FILA *F = fila_criar();	
	fila_inserir(F, raiz);
	//fila_imprimir(F);
	NO *aux;
	while(!fila_vazia(F)){
		aux = fila_retirar(F);
		printf(" %d", aux->item);
		if(aux->fesq != NULL) fila_inserir(F, aux->fesq);
		if(aux->fdir != NULL) fila_inserir(F, aux->fdir);
	}
}

NO *AVL_raiz(AVL *T){
	return T->raiz;
}

int esta_na_avl(NO *raiz, int item){
	if(raiz == NULL) return 0;
	if(raiz->item != item)
		return (esta_na_avl(raiz->fesq, item) || esta_na_avl(raiz->fdir, item));
	return 1;
}