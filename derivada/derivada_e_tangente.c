#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fila.h"
//#include "monomio.h"

int main(void){
	FILA *F = fila_criar(), *G = fila_criar();
	MON *m = NULL;
	long long x_0;
	scanf("%lld", &x_0);	
	while(!feof(stdin)){		
		fila_inserir(F); /*NOTE QUE O PILHA EMPILHAR JÁ LÊ OS DOIS NÚMEROS JUNTOS E EMPILHA UMA STRUCT NOVA*/				
		//n++;
	}
	fila_copiar(F, G);	/*CRIAR FUNÇÃO PARA COPIAR UMA PILHA CHEIA(P) PARA OUTRA VAZIA(Q), COM MESMOS ELEMENTOS*/
	//int derivada[pilha_tamanho(P)]; /* função */
	printf("f'(x) =");
	int prima=0;
	while(!fila_vazia(G)){
		//pilha_derivar_imprimir(Q); /*ESTA FUNÇÃO VAI IMPRIMINDO DERIVANDO = (Coeficiente)x^(Termo) OBS: termo igual a um => não imprimir o x e termo igual a zero => não imprimir nada*/				
		m = fila_retirar(G);
		if(monomio_coeficiente(m) != 0 && monomio_grau(m) != 0){
			if(prima++){ 
				if(monomio_coeficiente(m) * monomio_grau(m) > 0) printf(" +");
				else printf(" -");
			}
			if(monomio_grau(m) - 1 == 0){	
				printf(" %lld", llabs(monomio_coeficiente(m) * monomio_grau(m)));	
			}else if(monomio_grau(m) - 1 == 1) printf(" %lldx", llabs(monomio_coeficiente(m) * monomio_grau(m)));
			else printf(" %lldx^%lld", llabs(monomio_coeficiente(m) * monomio_grau(m)), monomio_grau(m) - 1);
		}
		monomio_apagar(m);
		m = NULL;
	}			
	printf("\n");
	/*PREPARAR PARA IMPRIMIR A FUNÇÃO G QUE É A RETA TANGENTE AO GRÁFICO NO PONTO x_0*/	
	printf("g(x) = ");
	long long angular = 0, f_do_ponto=0;
	while(!fila_vazia(F)){
		m = fila_retirar(F);
		f_do_ponto += monomio_resolver(m, x_0);
		angular += monomio_derivada(m, x_0);
		//printf("%ld\n", angular);
		monomio_apagar(m);
		m = NULL;
	}
	if(angular != 0){
		if((x_0 * angular - f_do_ponto) < 0)
			printf("%lldx + %lld\n", angular, llabs((x_0 * angular) - f_do_ponto));
		else 
			printf("%lldx - %lld\n", angular, llabs((x_0 * angular) - f_do_ponto));			
	}else{
		if((x_0 * angular - f_do_ponto) < 0)
			printf("%lld\n", llabs((x_0 * angular) - f_do_ponto));
		else 
			printf(" - %lld\n", llabs((x_0 * angular) - f_do_ponto));			
	}
	fila_apagar(G);
	fila_apagar(F);
	monomio_apagar(m);
	return 0;
}
