#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "monomio.h"

struct monomio{
	long long coef;
	long long grau;
};

MON *monomio_criar(void){
	MON *new = (MON *)malloc(sizeof(MON));
	if(new != NULL){
		new->coef = 0;
		new->grau = 0;
	}
	return new;
}

void monomio_apagar(MON *m){
	free(m);
	m = NULL;
}

void monomio_ler(MON *m){
	if(m != NULL){
		scanf("%lld%lld", &(m->coef), &(m->grau));
	}
}

long long monomio_coeficiente(MON *m){
	return(m->coef);
}

long long monomio_grau(MON *m){
	return(m->grau);
}

MON *monomio_definir(long long coef, long long grau){
	MON *new = monomio_criar();
	new->coef = coef;
	new->grau = grau;
	return new;
}

long long monomio_resolver(MON *m, long long x){
	long long res;
	if(m->grau != 0){	
		res = (m->coef * pow(x, m->grau));
	}else res = m->coef;	
	//printf("%d\n", res);
	return res;
}

long long monomio_derivada(MON *m, long long x){
	long long res;
	if(m->grau != 0){	
		res = (m->coef * m->grau * (long long)pow(x, (m->grau-1)));
	}else res = 0;
	//printf("x * coef * grau = %d, res = %d\n", (int)pow(x, (m->grau-1)) * m->coef * m->grau, res);	
	return res;
}
/*int monomio_resolver(MON *m, int x){
	return 	

}*/