#include <stdio.h>
#include <stdlib.h>
#include "text.h"

struct text{
	WORD **vet;
	int n_words;
};

TEXT *text_create(){
	TEXT *t = (TEXT *) malloc(sizeof(TEXT));
	//t->vet = (TEXT **)malloc(MAX * sizeof(TEXT*));
	t->vet = NULL;
	t->n_words = 0;
	return t;
}

void text_free(TEXT *t){
	if(t->vet != NULL){
		/*for(int i=0; i < t->n_words; i++){
			word_free((t->vet)[i]);
		}*/
		free(t->vet);
		t->vet = NULL;
	}else printf("Não existe palavras nesse texto.\n");
	if(t != NULL){	
		free(t);
		t = NULL;
	}else printf("Não existe este texto.\n");	
}

TEXT *text_read(FILE *fp){
	TEXT *t = text_create();
	int c;
	//while((c = fgetc(fp)) != EOF){
	while((c = fgetc(fp)) != EOF){
		fseek(fp, -1L, SEEK_CUR);
		t->vet = (WORD **) realloc(t->vet, ++(t->n_words) * sizeof(WORD*));
		//(t->vet)[t->n_words-1] = word_create();
		(t->vet)[t->n_words-1] = word_read(fp);
		//printf("%d\n", t->n_words);
		//word_print((t->vet)[t->n_words - 1]);		
	}
	return t;
}

void text_sort(TEXT *t){
	int i=0, j;
	WORD *chave = word_create();
	while(i < t->n_words){
		word_copy(t->vet[i], chave);
		j = i - 1;
		while(j >= 0 && word_compare(chave, t->vet[j]) < 0){
			word_copy(t->vet[j], t->vet[j+1]);	
			j--;
		}
		word_copy(chave, t->vet[j+1]);
		i++;
	}
	word_free(chave);
}

int text_word_equals(TEXT *t, int pos, int *after){
	int i = 0;
	int pos_or = pos;
	WORD *original = word_create();
	word_copy(t->vet[pos], original);
	while(word_compare(original, t->vet[pos]) == 0){
		i++;
		pos++;
		(*after)++;
	}
	while(word_compare(original, t->vet[pos_or]) == 0){
		i++;
		pos_or--;
	}
	word_free(original);
	return (i-1);	
}	

int binary_search(TEXT *t, WORD *w, int ini, int fim){
	int centro = (int)((ini+fim)/2);
	if(word_compare((t->vet)[centro], w) == 0) return centro;
	else{
		if(word_compare((t->vet)[centro], w) > 0){
			return binary_search(t, w, ini, centro-1);	
		}
		else{
			return binary_search(t, w, centro+1, fim);	
		}	
	}
}

WORD *text_get_word(TEXT *t, int pos){
	return(t->vet[pos]);
}

int text_get_n_words(TEXT* t){
	return (t->n_words);
}

void text_print_word(TEXT *t, int pos){
	word_print(t->vet[pos]);
}

void text_print(TEXT *t){
	for(int i=0; i<t->n_words; i++){
		word_print(t->vet[i]);
	}
}