#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Big_Integer.h"

struct big{
	char vet[MAX];
	int negative; /*negative == 1*/
	int num_Digits;
};

Big_Integer* create_Big_Integer(){
	Big_Integer *x = (Big_Integer *) malloc(sizeof(Big_Integer));
	if(x != NULL){
		x->num_Digits = 0;
	}
	return x;
}

void delete_Big_Integer(Big_Integer *x){
	if(x != NULL){
		free(x);
	}else printf("error - big integer does not exist.\n");
}

void set_Big_Integer(Big_Integer *x){
	if(x != NULL){
		//scanf("%MAXs%*c", x->vet);
		scanf("%1000s%*c", x->vet);
		x->negative = (x->vet[0] == '-' ? 1 : 0);
		x->num_Digits = strlen(x->vet);
	}else printf("error - big integer does not exist.\n");	
	
}

void print_Big_Integer(Big_Integer *x){
	if(x != NULL){
		for(int i = 0; i < x->num_Digits; i++){
			printf("%c", x->vet[i]);	
		}
		printf("\n");
	}else printf("error - big integer does not exist.\n");	
}

int get_num_Digits(Big_Integer *x){
	return (x != NULL ? x->num_Digits : 0);
}

int is_negative(Big_Integer *x){
	return (x != NULL ? x->negative : 0);
}

Big_Integer *sum_Big_Integers(Big_Integer *a, Big_Integer *b){
	Big_Integer *soma = create_Big_Integer();
	int ai, bi, s, carry = 0, i, j, k;
	soma->num_Digits = (a->num_Digits > b->num_Digits ? a->num_Digits : b->num_Digits) + 1;
	soma->vet[soma->num_Digits] = '\0'; //Fim da string soma
    for(i = (a->num_Digits) - 1, j = (b->num_Digits) - 1, k = (soma->num_Digits) - 1; k >= 0; i--, j--, k--){
        ai = i >= 0 ? a->vet[i] - '0' : 0; //Se ainda está dentro do vetor converte o
        bi = j >= 0 ? b->vet[j] - '0' : 0; //caractere para inteiro, senão guarda 0.
        s = ai + bi + carry; //Soma
        soma->vet[k] = s % 10 + '0'; //Guarda apenas 1 digito como caractere
        carry = s / 10; //Carrega o que sobrou para somar no próximo ciclo
    }
    //Elimina o zero à esquerda da soma, se o último carry não carregou nada:
    if(soma->vet[0] == '0'){
        for(i = 0; soma->vet[i]; i++){ //move todos os caracteres 1 posição
            soma->vet[i] = soma->vet[i+1];
        }
    }
    printf("%s\n", soma->vet);
    return soma;
}

Big_Integer *subtract_Big_Integers(Big_Integer *a, Big_Integer *b){
	Big_Integer *sub = create_Big_Integer();
    int i, j, k, borrow = 0, ai, bi, s;
	if(a->num_Digits > b->num_Digits){
		sub->num_Digits = a->num_Digits;
		sub->vet[sub->num_Digits] = '\0'; //Fim da string sub
		for(i = (a->num_Digits) - 1, j = (b->num_Digits) - 1, k = (sub->num_Digits) - 1; k >= 0; i--, j--, k--){
        	ai = i >= 0 ? a->vet[i] - '0' : 0; //Se ainda está dentro do vetor converte o
        	bi = j >= 0 ? b->vet[j] - '0' : 0; //caractere para inteiro, senão guarda 0.
        	if((ai -= borrow) >= bi){	/*subtração*/
        		s = ai - bi;
        		borrow = 0;
        	}else{
        		s = ai + 10 - bi;
        		borrow = 1;
        	}
        	sub->vet[k] = s + '0'; //Guarda apenas 1 digito como caractere	
        }
        //carry = s / 10; //Carrega o que sobrou para somar no próximo ciclo    	
	}else{
		sub->num_Digits = a->num_Digits;
		sub->vet[sub->num_Digits] = '\0'; //Fim da string sub
		sub->vet[0] = '-';
		for(i = (a->num_Digits) - 1, j = (b->num_Digits) - 1, k = (sub->num_Digits); k > 0; i--, j--, k--){
        	ai = i >= 0 ? a->vet[i] - '0' : 0; //Se ainda está dentro do vetor converte o
        	bi = j >= 0 ? b->vet[j] - '0' : 0; //caractere para inteiro, senão guarda 0.
        	if((ai -= borrow) >= bi){	/*subtração*/
        		s = ai - bi;
        		borrow = 0;
        	}else{
        		s = ai + 10 - bi;
        		borrow = 1;
        	}
        	sub->vet[k] = s + '0'; //Guarda apenas 1 digito como caractere
		}
	}	
	printf("%s\n", sub->vet);
	return sub;
}

/*Big_Integer *multiply_Big_Integers(Big_Integer *a, Big_Integer *b);
Big_Integer *divide_Big_Integers(Big_Integer *a, Big_Integer *b);*/