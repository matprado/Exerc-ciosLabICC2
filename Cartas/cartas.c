#include <stdio.h>
#include "fila.h"

int main(void){
	int n, item, *vet;
	FILA *F = NULL;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		F = fila_criar();
		while(item != 0){
			scanf("%d", &item);
			if(item == 0) break;
			fila_inserir(F, item);
		}
		printf("Cartas jogadas:");
		while(!fila_vazia(F)){
			item = fila_retirar(F);
			if(fila_vazia(F)){
				break;
			}
			fila_inserir(F, fila_retirar(F));
			printf(" %d", item);	
		}
		printf("\n");
		printf("Carta restante: %d\n", item);
		fila_apagar(F);
		item = 2;
	}

}