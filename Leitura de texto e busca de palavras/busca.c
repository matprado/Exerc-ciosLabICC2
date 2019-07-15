#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
/*Este programa abre um arquivo, lê todas as palavras do texto ordenando as mesmas e realiza uma busca indicando a quantidade de aparições da palavra e as três palavras seguintes na ordem*/

int main(int argc, char *argv[]){
	/*abertura do arquivo com a leitura do nome*/
	char *nome = (char*) malloc(20 * sizeof(char));
	int i, N, pos, qtd;
	scanf("%s", nome);
	nome[strlen(nome)] = '\0';
	//printf("%s\n", nome);
	FILE *fp;
	if(nome[0] == 'a'){
		if((fp = fopen("alice.txt", "rb")) == NULL){
			printf("erro ao abrir arquivo de leitura\n");
			return 1;	
		}
	}else if(nome[0] == 'h'){	
		if((fp = fopen("hauntedhouse.txt", "rb")) == NULL){
			printf("erro ao abrir arquivo de leitura\n");
			return 1;	
		}
	}else{
		if((fp = fopen("jumpingFrog.txt", "rb")) == NULL){
			printf("erro ao abrir arquivo de leitura\n");
			return 1;	
		}
	}	
	free(nome);
	/*processo de leitura de todas as palavras do texto para ordená-las posteriormente*/
	TEXT *t = text_read(fp);
	//printf("ENTROU NESSE ACAEFEFIAOAFNA\n"); 
	/*hora de ordenar o vetor de palavras:*/
	text_sort(t);
	/*leitura das palavras procuradas(CHAVES)*/
	scanf("%d", &N);
	TEXT *chaves = text_read(stdin);
	WORD *chave = (WORD *) word_create();
	int n = text_get_n_words(t);
	int *depois = (int*) malloc(1 * sizeof(int));
	for(i=0; i<N; i++){
		//resposta_final(text->palavras ,chaves[i], text->n);
		chave = text_get_word(chaves, i);
		pos = binary_search(t, chave, 0, n);
		*(depois) = 0;
		qtd = text_word_equals(t, pos, depois);
		word_print(chave);
		printf("%d ", qtd);
		text_print_word(t, pos+(*depois));
		text_print_word(t, pos+((*depois)+1));
		text_print_word(t, pos+((*depois)+2));
		printf("\n");
	}  
    /*liberação de memória e de arquivo de leitura*/
	free(depois);
	word_free(chave);
    text_free(chaves);
    text_free(t);  		
	fclose(fp);
	return 0;
}