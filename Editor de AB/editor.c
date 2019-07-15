#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main(void){
	ABB *T = arv_criar();
	char op, c;
	int chave;
	do{
		scanf("%c", &op);
		switch(op){
			case 'I':
				scanf("%d%c", &chave, &c);
				if(!abb_inserir(T, chave)) printf("Chave existente\n");;
				break;
			case 'D':
				scanf("%d%c", &chave, &c);
				chave = abb_busca(ABB_raiz(T), chave);
				if(chave == -404){
					printf("Nao encontrado\n");
				}
				else{
					abb_remover_aux(ABB_raiz(T), ABB_raiz(T), NULL, chave);
					printf("%d\n", chave);
				}
				break;
			case 'B':
				scanf("%d%c", &chave, &c);
				chave = abb_busca(ABB_raiz(T), chave);
				if(chave != -404)
					printf("Encontrado\n");
				else
					printf("Nao encontrado\n");
				break;
			case 'N':
				printf("InOrdem:");
				em_ordem(ABB_raiz(T));
				printf("\n");
				break;
			case 'E':
				printf("PreOrdem:");
				pre_ordem(ABB_raiz(T));
				printf("\n");
				break;
			case 'O':
				printf("PosOrdem:");
				pos_ordem(ABB_raiz(T));
				printf("\n");
				break;
			case 'L':
				printf("Largura:");
				imprimir_largura(ABB_raiz(T));
				printf("\n");
				break;
			case 'Y':
				printf("InOrdem:");
				em_ordem(ABB_raiz(T));
				printf("\n");
				printf("PreOrdem:");
				pre_ordem(ABB_raiz(T));
				printf("\n");
				printf("PosOrdem:");
				pos_ordem(ABB_raiz(T));
				printf("\n");
				printf("Largura:");
				imprimir_largura(ABB_raiz(T));
				printf("\n");;
				break;		
		}
	}while(op != 'X');
	return 0;
}