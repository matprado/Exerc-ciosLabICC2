#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Define a struct de coordenadas x e y;
 * 
 * */
typedef struct coord COORD;
struct coord{
	float x;
	float y;	
};
/*
 * função distancia:
 * Calcula a distancia entre dois pontos;
 * 
 * @Argumentos:
 * COORD x1, COORD x2 = Duas coordenadas para se calcular a distância entre elas;
 * 
 * @Retorno:
 * float dist = distancia entre as coordenadas;	
 * */
float distancia(COORD x1, COORD x2){
	float dist = sqrtf(pow((x2.y - x1.y), 2) + pow((x2.x - x1.x), 2));	
	return dist;
}	

/* coelho desloca x, raposa desloca 2x*/

int main(int argc, char *argv[]){
	int n;
	COORD coelho, raposa;
	scanf("%d", &n);
	scanf("%f", &coelho.x);
	scanf("%f", &coelho.y);
	scanf("%f", &raposa.x);
	scanf("%f", &raposa.y);
	COORD buraco[n];
	int i;
	int ja_foi = 0;/*coordenada para saber se já achou o buraco;*/
	for(i = 0; i < n; i++){
		scanf("%f", &(buraco[i]).x);	
		scanf("%f", &(buraco[i]).y);
		if(distancia(coelho, buraco[i]) < (distancia(raposa, buraco[i]) / 2.0)){
			printf("O coelho pode escapar pelo buraco (%.3f,%.3f).\n", buraco[i].x, buraco[i].y);
			ja_foi++;
			break;		
		}
	}
	if(ja_foi == 0){
		printf("O coelho nao pode escapar.\n");	
	}
	return 0;
}
