#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include "word.h"

struct word{
	char string[30];
};

WORD *word_create(){
	WORD *w = (WORD *) malloc(sizeof(WORD));
	//w->string = (char *) malloc(40 * sizeof(char));
	return w;
}

void word_free(WORD *w){
	/*free(w->string);
	w->string = NULL;*/
	free(w);
	w = NULL;
}

WORD *word_read(FILE *fp){
	WORD *w = word_create();
	int c;
	int ascii, i = 0;
	if(w == NULL){
	 	printf("não existe tal palavra...\n");
	 	exit(0);
	}else{
		c = fgetc(fp);
		/*conferir se há caractere especial no começo:*/           
		ascii = (int)c;
		while((ascii < 65 || (ascii > 90 && ascii < 97) || ascii > 122) && ascii != 45 && c != EOF){
			c = fgetc(fp);
			ascii = (int)c;	
		}
		/*agora confere o final da palavra(ocorrencia de um desses caracteres especias)*/
		while(((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122) || ascii == 45 )&& c != EOF){
			if(ascii <= 90 && ascii != 45)	c = (char)(ascii + 32);  	
			w->string[i++] = c;
			c = fgetc(fp);
			ascii = (int)c;	
		}
		w->string[i] = '\0';	
		return w;
	}
}


/*RETURN VALUES:
- return == 0 --> the words are equal;
- return > 0 --> the first word comes first in the alphabet;
- return < 0 --> the second word comes first in the alphabet;
*/
int word_compare(WORD *w1 , WORD *w2){
	return(strcmp(w1->string, w2->string)); 
}

void word_copy(WORD *source, WORD *copy){
	strcpy(copy->string, source->string);	
}

void word_print(WORD* w){
	printf("%s ", w->string);
}