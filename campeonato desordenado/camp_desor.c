#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char *nome;
	char *origem; //CAASO ou FEDERAL
}corredor;

#define MAX_LETRAS 50

void merge(corredor *vet, int ini, int meio, int fim, int (*compara_corredores)(corredor *a, corredor *b), int comp, int *z){
	if(*z >= comp) return;
	corredor *aux = (corredor*)malloc((fim-ini+1) * sizeof(corredor));
	int i=ini, j=meio+1, k;	
    for(k=0; i<=meio && j<=fim; k++){	//Ordena os dois 'blocos'
    	//if(vet[i] < vet[j])
    	if(compara_corredores(&vet[i], &vet[j]) < 0) // 1º menor que 2º -> verdadeiro
    		aux[k] = vet[i++];
    	else
    		aux[k] = vet[j++];
    }
    while(i <= meio){  //Caso ainda haja elementos na primeira metade
        aux[k++] = vet[i++];
    }
    while(j <= fim){   //Caso ainda haja elementos na segunda metade
        aux[k++] = vet[j++];
    }
    for(k = ini; k <= fim; k++){//Move os elementos de volta para o vetor original
        vet[k] = aux[k-ini];
    }
    free(aux);
}

void merge_sort(corredor *vet, int ini, int fim, int (*compara_corredores)(corredor *a, corredor *b), int comp, int *i){
	if(fim <= ini)	return;
	int meio = (int) (ini+fim-1)/2;	
	merge_sort(vet, ini, meio, compara_corredores, comp, i);
	merge_sort(vet, meio+1, fim, compara_corredores, comp, i);
	merge(vet, ini, meio, fim, compara_corredores, comp, i);
	(*i)++;
}

int compara_id(corredor *a, corredor *b){
	return (a->id - b->id);
}

int compara_nome(corredor *a, corredor *b){
	return (strcmp(a->nome, b->nome));
}

int main(void){
	corredor *vet = NULL;
	char c, *origem = (char *) malloc(10 * sizeof(char)), *nome = (char *) malloc(MAX_LETRAS * sizeof(char));
	int i=0, comparacoes, n=0, id;
	while(!feof(stdin)){
		c = getchar();
		//printf("c é %c\n", c);
		switch(c){
			case 'F':
				strcpy(origem, "");
				fseek(stdin, -1L, SEEK_CUR);
				scanf("%[^\n]s", origem);
				fflush(stdin);
				origem[strlen(origem)-1] = '\0';
				//printf("origem = %s\n", origem);
				break;
			case 'C':
			strcpy(origem, "");
				fseek(stdin, -1L, SEEK_CUR);
				scanf("%[^\n]s", origem);
				fflush(stdin);
				origem[strlen(origem)-1] = '\0';
				/*while(c != '\n'){
					origem[i++] = c;
					c = getchar();
				}*/
				//printf("origem = %s\n", origem);
				break;
			case 'I': //ID
				c = getchar();c = getchar();	
				scanf("%d", &comparacoes);
				/*for(i=0; i<n; i++){
					printf("%s %d %s\n", vet[i].origem, vet[i].id, vet[i].nome);
				}*/
				merge_sort(vet, 0, n-1, &compara_id, comparacoes, &i);
				break;
			case 'N':
				c = getchar();c = getchar();c = getchar();c = getchar();
				scanf("%d", &comparacoes);	
				merge_sort(vet, 0, n-1, &compara_nome, comparacoes, &i);
				break;
			default:
				fseek(stdin, -1L, SEEK_CUR);
				//id = c - '0';
				scanf("%d", &id);
				c = getchar();
				if(c)
				//scanf("%s", nome);
				scanf("%[^\n]s", nome);
				fflush(stdin);
				//getline(&nome, &size, stdin);
				nome[strlen(nome)-1] = '\0';
				//printf("%s\n", nome);
				vet = (corredor *) realloc(vet, ++n * sizeof(corredor));
				(vet[n-1]).nome = (char *) malloc(MAX_LETRAS * sizeof(char));
				strcpy((vet[n-1]).nome, nome);
				(vet[n-1]).id = id;
				(vet[n-1]).origem = (char *) malloc(10 * sizeof(char));
				strcpy((vet[n-1]).origem, origem);
				//printf("origem = %s\n", vet[n-1].origem);
				getchar();
				break;		
		}
	}
	for(i=0; i<n; i++){
		printf("%s %d %s\n", vet[i].origem, vet[i].id, vet[i].nome);
	}
	//printf("COMPARACOES = %d\n", comparacoes);
	free(vet);
	free(origem);
	free(nome);
	return 0;
}