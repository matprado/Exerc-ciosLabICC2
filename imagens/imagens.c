#include <stdio.h>
#include <stdlib.h>
#include "arvore_quaternaria.h"

int main(){
	ARVORE *T1;
	ARVORE *T2;
	int n;
	char barra;
	ARVORE *T3;
	scanf("%d%c", &n, &barra);
	for(int i=0; i<n; i++){
		T1 = criar_arvore();
		T2 = criar_arvore();
		montar_arvore(T1);
		//imprimir_arvore(T1);
		//printf("\n");
		//scanf("%c", &barra);
		scanf("%c", &barra);
		montar_arvore(T2);
		//imprimir_arvore(T2);
		//printf("\n");
		scanf("%c", &barra);
		T3 = sobreposicao_de_arvores(T1, T2);
		//imprimir_arvore(T3);
		//printf("\n");
		printf("%d %d pixels pretos.\n", i+1, pixels_pretos(T3));
		/*apagar_arvore(T1);
		apagar_arvore(T2);
		apagar_arvore(T3);*/
	}
	return 0;
}	