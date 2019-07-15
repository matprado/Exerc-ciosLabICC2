#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void le_tela(const int linhas, const int colunas, char tela[linhas][colunas]){
	char c;
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++){
			scanf("%c", &tela[i][j]);
		}
		c = getchar();
	}
}

void imprime_tela(const int linhas, const int colunas, char tela[linhas][colunas]){
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++){
			printf("%c", tela[i][j]);
		}
		printf("\n");
	}
}

/*void pintar(const int linhas, const int colunas, char tela[linhas][colunas], int i, int j, char cor, char espaco){
	if(i < 0 || i >= linhas || j < 0 || j >= colunas) return;
	if(tela[i][j] == cor) return;
	if(tela[i][j] != espaco) return;
	tela[i][j] == cor;
	pintar(linhas, colunas, tela, i+1, j, cor, espaco);
	pintar(linhas, colunas, tela, i-1, j, cor, espaco);
	pintar(linhas, colunas, tela, i, j+1, cor, espaco);
	pintar(linhas, colunas, tela, i, j-1, cor, espaco);
}*/

int main(void){
	PILHA *P = pilha_criar();
	int linhas, colunas;
	scanf("%d%d", &linhas, &colunas);
	char tela[linhas][colunas], cor;
	cor = getchar();
	le_tela(linhas, colunas, tela);
	int x,y;
	char espaco, c;
	NO *atual;
	while(scanf("%d%d %c", &x, &y, &cor) != EOF){
		//pega as coordenadas e o char a ser pintado
		//c = getchar();		
		espaco = tela[x][y];
		pilha_empilhar(P, x, y); /* empilha as coordenadas do primeiro*/
		while(!pilha_vazia(P)){
			atual = pilha_desempilhar(P);	
			tela[x_no(atual)][y_no(atual)] = cor;
			if(x_no(atual)+1 < linhas && tela[x_no(atual)+1][y_no(atual)] == espaco){
				pilha_empilhar(P, x_no(atual)+1, y_no(atual));
			}
			if(x_no(atual)-1 >= 0 && tela[x_no(atual)-1][y_no(atual)] == espaco){
				pilha_empilhar(P, x_no(atual)-1, y_no(atual));
			}
			if(y_no(atual)+1 < colunas && tela[x_no(atual)][y_no(atual)+1] == espaco){
				pilha_empilhar(P, x_no(atual), y_no(atual)+1);
			}
			if(y_no(atual)-1 >= 0  && tela[x_no(atual)][y_no(atual)-1] == espaco){
				pilha_empilhar(P, x_no(atual), y_no(atual)-1);
			}
			free(atual);
		}
		imprime_tela(linhas, colunas, tela);
	}
	pilha_apagar(&P);
	return 0;
}