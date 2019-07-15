#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
	MON *poli[MAX];
	int n;
};

FILA *fila_criar(void){
	FILA *new = (FILA *)malloc(sizeof(FILA));
	if(new != NULL){
		for(int i=0; i<MAX; i++){
			new->poli[i] = NULL;
		}
		new->n = 0;
	}
	return new;
}

void fila_apagar(FILA *F){
	if(F != NULL){
		if(!fila_vazia(F)){
			for(int i=0; i<F->n; i++){
				monomio_apagar(F->poli[i]);
			}
		}
		free(F);
		F = NULL;
	}
}

void fila_inserir(FILA *F){
	if(F != NULL && !fila_cheia(F)){ 
		//printf("banana\n");
	 	F->poli[F->n] = monomio_criar();
	 	monomio_ler(F->poli[F->n]);
	 	F->n++;
	}	
}

MON *fila_retirar(FILA *F){
	/*RETIRAR O PRIMEIRO E MOVER TODOS OS PŔOXIMOS UMA POSIÇÃO PARA TRÁS*/
	MON *ret = NULL;
	int i = 0;
	if(F != NULL && !fila_vazia(F)){
		ret = F->poli[0];
		while(i < F->n){
			F->poli[i] = F->poli[i+1];
			i++;
		}
		monomio_apagar(F->poli[F->n]);
		F->n--;
	}
	return ret;
}

int fila_vazia(FILA *F){
	return(F->n == 0);
}

int fila_cheia(FILA *F){
	return(F->n == MAX);
}

void fila_copiar(FILA *orig, FILA *copia){
	int n = orig->n;
	copia->n = n;
	for(int i=0; i<n; i++){
		//copia->poli[i]->coef = orig->poli[i]->coef;
		copia->poli[i] = monomio_definir(monomio_coeficiente(orig->poli[i]), monomio_grau(orig->poli[i]));
		//copia->poli[i]->grau = orig->poli[i]->grau;
	}
}