#include "lista.h"
#include <stdio.h>

int main(void){
	LISTA *L = lista_criar();
	int tempo = 0, chave, j;
	char c;
	do{
		scanf("%c", &c);
		switch(c){
			case 'i':
				scanf("%d%d%c", &chave, &j, &c);
				lista_inserir_fim(L, tempo, chave, j);
				//printf("INSERIU\n");
				tempo++;
				break;
			case 'r':
				scanf("%d%c", &chave, &c);
				lista_remover_item(L, chave);	
				//printf("REMOVEU\n");
				tempo++;
				break;
		}
	}while(c != 'f');
	if(lista_vazia(L)) printf("-1\n");
	else lista_imprimir(L);
	lista_apagar(L);
	return 0;
}