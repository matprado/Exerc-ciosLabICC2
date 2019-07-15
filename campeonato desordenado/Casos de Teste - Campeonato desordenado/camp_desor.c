#include <stdio.h>
#include <stdlib.h>
#include <stding.h>

typedef struct{
	int id;
	char *nome;
	char *origem; //CAASO ou FEDERAL
}corredor;

void merge_sort(corredor *vet, int ini, int fim, int *compara_corredores(corredor a, corredor b)){
	if(fim <= ini)	return;
	int meio = (int) (ini+fim)/2;	
	merge_sort(vet, ini, meio, compara_corredores());
	merge_sort(vet, meio+1, fim, compara_corredores());
	merge(vet, ini, meio, fim, compara_corredores());
}

void merge(corredor *vet, int ini, int meio, int fim, int *compara_corredores(corredor a, corredor b)){
	corredor *aux = (corredor*)malloc((fim-ini+1) * sizeof(corredor));
	int i, j, k;	
    for(i=ini, j=meio+1, k=0; i<=meio, j<=fim; k++){	//Ordena os dois 'blocos'
    	//if(vet[i] < vet[j])
    	if(compara_corredores(vet[i], vet[j]) < 0) // 1º menor que 2º -> verdadeiro
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

int compara_id(corredor a, corredor b){
	return (a.id - b.id);
}

int compara_nome(corredor a, corredor b){
	return (strcmp(a.nome, b.nome));
}

int main(void){
	corredor *vet = NULL;
	char c, *origem = (char *) malloc(10 * sizeof(char)), nome = (char *) malloc(30 * sizeof(char));
	int i=0, comparacoes, n=0, id;
	while(!feof(stdin)){
		c = getchar();
		swicth(c){
			case 'F':
				while(c != '\n'){
					origem[i++] = c;
					c = getchar();
				}
				origem[i] = '\0';
				i=0;
				break;
			case 'C':
				while(c != '\n'){
					origem[i++] = c;
					c = getchar();
				}
				origem[i] = '\0';
				i=0;
				break;
			case 'I': //ID
				c = getchar();c = getchar();	
				scanf("%d", &comparacoes);
				merge_sort(corredor*, 0, n-1, &compara_id());
				break;
			case 'N':
				c = getchar();c = getchar();c = getchar();c = getchar();
				scanf("%d", &comparacoes);
				merge_sort(corredor*, 0, n-1, &compara_nome());
				break;
			default:
				id = c - '0';
				c = getchar();
				scanf("%s", nome);
				nome[strlen(nome)] = '\0';
				vet = (corredor *) realloc(++n * sizeof(corredor));3
				(corredor[n-1]).nome = nome;
				(corredor[n-1]).id = id;
				break;		
		}
	}
	free(vet);
	free(origem);
	free(nome);
	return 0;
}