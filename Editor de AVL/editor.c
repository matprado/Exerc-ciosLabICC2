#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


int main(void){
	char op = 'm';
	int chave;
	AVL *arvore = avl_criar();
	do{
		scanf("%c", &op);
		switch(op){
			case 'I':
				scanf("%d", &chave);
				if(!avl_inserir(arvore, chave)) printf("Chave existente\n");
				break;
			case 'N':
				printf("InOrdem:");
				em_ordem(AVL_raiz(arvore));
				printf("\n");
				break;
			case 'E':
				printf("PreOrdem:");
				pre_ordem(AVL_raiz(arvore));
				printf("\n");
				break;
			case 'O':
				printf("PosOrdem:");
				pos_ordem(AVL_raiz(arvore));
				printf("\n");
				break;
			case 'L':
				printf("Largura:");
				imprimir_largura(AVL_raiz(arvore));
				printf("\n");
				break;
			case 'Y':
				printf("InOrdem:");
				em_ordem(AVL_raiz(arvore));
				printf("\n");
				printf("PreOrdem:");
				pre_ordem(AVL_raiz(arvore));
				printf("\n");
				printf("PosOrdem:");
				pos_ordem(AVL_raiz(arvore));
				printf("\n");
				printf("Largura:");
				imprimir_largura(AVL_raiz(arvore));
				printf("\n");;
				break;	
		}
		getchar();
	}while(op != 'X');
	avl_apagar(&arvore);
	return 0;
}