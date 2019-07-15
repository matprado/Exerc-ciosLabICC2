#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct big Big_int;

struct big{
	char vet[1000];
	int n;
};


Big_int le_big(){
	Big_int num;
	scanf("%1000s%*c", num.vet);
	num.n = strlen(num.vet);
	return num;
}

void soma(Big_int a, Big_int b){
	Big_int soma;
	int ai, bi, s, carry = 0, i, j, k;
	soma.n = (a.n > b.n ? a.n : b.n) + 1;
	soma.vet[soma.n] = '\0'; //Fim da string soma
    for(i = (a.n) - 1, j = (b.n) - 1, k = (soma.n) - 1; k >= 0; i--, j--, k--){
        ai = i >= 0 ? a.vet[i] - '0' : 0; //Se ainda está dentro do vetor converte o
        bi = j >= 0 ? b.vet[j] - '0' : 0; //caractere para inteiro, senão guarda 0.
        s = ai + bi + carry; //Soma
        soma.vet[k] = s % 10 + '0'; //Guarda apenas 1 digito como caractere
        carry = s / 10; //Carrega o que sobrou para somar no próximo ciclo
    }
    
    //Elimina o zero à esquerda da soma, se o último carry não carregou nada:
    if(soma.vet[0] == '0'){
        for(i = 0; soma.vet[i]; i++){ //move todos os caracteres 1 posição
            soma.vet[i] = soma.vet[i+1];
        }
    }
    printf("%s\n", soma.vet);
}

void subtracao(Big_int a, Big_int b){
	Big_int sub;
    int i, j, k, borrow = 0, ai, bi, s;
    sub.n = (a.n > b.n ? a.n : b.n);
	sub.vet[sub.n] = '\0'; //Fim da string soma
    for(i = (a.n) - 1, j = (b.n) - 1, k = (sub.n) - 1; k >= 0; i--, j--, k--){
        ai = i >= 0 ? a.vet[i] - '0' : 0; //Se ainda está dentro do vetor converte o
        bi = j >= 0 ? b.vet[j] - '0' : 0; //caractere para inteiro, senão guarda 0.
        if((ai -= borrow) >= bi){	/*subtração*/
        	s = ai - bi;
        	borrow = 0;
        }else{
        	s = ai + 10 - bi;
        	borrow = 1;
        }
        sub.vet[k] = s + '0'; //Guarda apenas 1 digito como caractere
        //carry = s / 10; //Carrega o que sobrou para somar no próximo ciclo
    }
    //Elimina o zero à esquerda da soma, se o último carry não carregou nada:
    if(sub.vet[0] == '0'){
        for(i = 0; sub.vet[i]; i++){ //move todos os caracteres 1 posição
            sub.vet[i] = sub.vet[i+1];
        }
    }
    for(i = 0; sub.vet[i] == '0' && i < (sub.n) - 1; i++);
    strcpy(sub.vet, &sub.vet[i]);
    printf("%s\n", sub.vet);
}

int main(int argc, char *argv[]){
	char op[20];
	fgets(op, 20, stdin);
	Big_int n1, n2;
	n1 = le_big();
	n2 = le_big();
	if(!strcmp(op, "SOMA\n")){
		soma(n1, n2);
	}else if(!strcmp(op, "SUBTRACAO\n")){
		subtracao(n1, n2);
	}
	return 0;
}