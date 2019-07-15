#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvore_quaternaria.h"

struct arvore{
	NO *raiz;
};

struct no{
	NO* nordeste;
	NO* noroeste;
	NO* sudoeste;
	NO* sudeste;
	int filhos;
	char estado;
};

ARVORE *criar_arvore(){
	ARVORE *T = (ARVORE *) malloc(sizeof(ARVORE));
	if(T != NULL){
		T->raiz = NULL;
	}
	return T;
}

NO *criar_no(){
	NO *new = (NO *) malloc(sizeof(NO));
	if(new != NULL){
		new->estado = ' ';
		new->nordeste = NULL;
		new->noroeste = NULL;
		new->sudoeste = NULL;
		new->sudeste = NULL;
		new->filhos = 0;
	}
	return new;
}

NO *criar_no_lendo(){
	NO *new = (NO *) malloc(sizeof(NO));
	if(new != NULL){
		scanf("%c", &(new->estado));
		//printf("%c", new->estado);
		new->nordeste = NULL;
		new->noroeste = NULL;
		new->sudoeste = NULL;
		new->sudeste = NULL;
		new->filhos = 0;
	}
	return new;
}

void montar_arvore(ARVORE *T){
	T->raiz = montar_no(T);
}

NO *montar_no(ARVORE *T){
	//if(node == NULL) return;
	NO *node = criar_no_lendo();
	//printf("%c", node->estado);
	if(node->estado == 'p'){
		node->filhos = 4;
		node->nordeste = montar_no(T);
		node->noroeste = montar_no(T);
		node->sudoeste = montar_no(T);
		node->sudeste = montar_no(T);
	}
	return node;	
}


void apagar_arvore(ARVORE *T){
	apagar_no(T->raiz);
}

void apagar_no(NO *node){
	if(node == NULL) return;
	char estado = node->estado;
	free(node);
	if(estado == 'p'){
		apagar_no(node->nordeste);
		apagar_no(node->noroeste);
		apagar_no(node->sudoeste);
		apagar_no(node->sudeste);
	}
}

ARVORE *sobreposicao_de_arvores(ARVORE *T1, ARVORE *T2){
	ARVORE *S = criar_arvore();
	S->raiz = sobreposicao_de_nos(T1->raiz, T2->raiz);
	return S;
}

NO *sobreposicao_de_nos(NO *n1, NO *n2){
	if(n1 == NULL || n2 == NULL) return	NULL;
	NO *s;
	//s = criar_no();
	if(n1->estado == 'f' || n2->estado == 'f'){
		//s->estado = 'f';
		s = criar_no();
		s->estado = 'f';
	}else if(n1->estado == 'p' && n2->estado == 'e'){
		s = n1;
	}else if(n1->estado == 'e' && n2->estado == 'p'){
		s = n2;
	}else if(n1->estado == 'e' && n2->estado == 'e'){
		s = n1;
	}else{
		s = criar_no();
		s->estado = 'p';
		s->nordeste = sobreposicao_de_nos(n1->nordeste, n2->nordeste);
		s->noroeste = sobreposicao_de_nos(n1->noroeste, n2->noroeste);
		s->sudoeste = sobreposicao_de_nos(n1->sudoeste, n2->sudoeste);
		s->sudeste = sobreposicao_de_nos(n1->sudeste, n2->sudeste);
	}
	//printf("estado: %c\n", s->estado);
	return s;
}

int pixels_pretos(ARVORE *T){
	int pp = 0, nivel = 0;
	contar_pp(T->raiz, &pp, &nivel);
	return pp;
}

void contar_pp(NO *node, int *pp, int *nivel){
	if(node == NULL) return;
	if(node->estado == 'f'){
		//printf("pp=%d,nivel=%d\n", *pp, (*nivel));
		(*pp) += 32 * 32 / pow(4, (*nivel));
	}
	else if(node->estado == 'p'){
		(*nivel)++;
		contar_pp(node->nordeste, pp, nivel);
		contar_pp(node->noroeste, pp, nivel);
		contar_pp(node->sudoeste, pp, nivel);
		contar_pp(node->sudeste, pp, nivel);
		(*nivel)--;
	}
}

void imprimir_arvore(ARVORE *T){
	imprimir_no(T->raiz);
}

void imprimir_no(NO *node){
	if(node == NULL) return;
	printf("%c", node->estado);
	if(node->estado == 'p'){
		imprimir_no(node->nordeste);
		imprimir_no(node->noroeste);
		imprimir_no(node->sudoeste);
		imprimir_no(node->sudeste);		
	}
}