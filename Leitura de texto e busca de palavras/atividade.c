#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Este programa abre um arquivo, lê todas as palavras do texto ordenando as mesmas e realiza uma busca indicando a quantidade de aparições da palavra e as três palavras seguintes na ordem*/

#define DEBUG 0
typedef struct texto TEXTO;
struct texto{
	char **palavras;
	int n;
};


/* função le_palavra: le uma palavra no texto do arquivo;
 * @Parâmetros:
 * - um ponteiro para arquivo de leitura;
 * 
 * @retorno:
 * - uma string com a palavra lida;
 * */
char *le_palavra(FILE *fp){
	char c;
	char *palavra = (char *) malloc(20 * sizeof(char));
	c = fgetc(fp);
	/*conferir se há caractere especial no começo:*/           
	int ascii = (int)c;
	/*while(c == ' ' || c == ',' || c == '.' || c == ';' || c == '\'' || c == '?' || c == ':' || c == '/' || c == '!' || c == '*'|| c == '"'){
		c = fgetc(fp);	
		ascii = (int)c;
	}*/
	/*ideia = usar ASCII*/
	while((ascii < 65 || (ascii > 90 && ascii < 97) || ascii > 122) && ascii != 45){
		c = fgetc(fp);
		ascii = (int)c;	
	}
	int i=0;
	/*agora confere o final da palavra(ocorrencia de um desses caracteres especias)*/	
	/*while(c != ' ' && c != ',' && c != '.' && c != ';' && c != '\'' && c != '?' && c != ':' && c != '/' && c != '!' && c != '*' && c != '"'){
		if(ascii <= 90){
			c = (char)(ascii + 32);  	
		}
		palavra[i++] = c; 
		c = fgetc(fp);
		ascii = (int)c;
	}*/
	while((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122) || ascii == 45){
		if(ascii <= 90 && ascii != 45){
			c = (char)(ascii + 32);  	
		}
		//printf("%c\n", c);
		palavra[i++] = c;
		c = fgetc(fp);
		ascii = (int)c;	
	}
	/*acho que não precisa dar fseek*/
	//fseek(fp, -1L, SEEK_CUR);
	palavra[i] = '\0'; // fim da string;
	//printf("%s\n", palavra);
	return palavra;
}	

/* função texto_scanner: le todas as palavras de um arquivo;
 * @Parâmetros:
 * - um ponteiro para arquivo de leitura;
 * 
 * @retorno:
 * - um vetor de strings com  todas as palavras lidas;
 * */
TEXTO *texto_scanner(FILE *fp){
	TEXTO *text = (TEXTO*) malloc(sizeof(TEXTO));
	//char **leitura = NULL;
	text->palavras = NULL;
	text->n = 0;
	char c;
	/*enquanto não estiver no fim do arquivo, lê as palavras e armazena no vetor de strings(char **)...*/
	while((c = fgetc(fp))!= EOF){
		fseek(fp, -1L, SEEK_CUR);
		(text->palavras) = (char **) realloc((text->palavras), ++(text->n) * sizeof(char *));  // O ERRO TÁ AQUI...
		//(text->palavras)[(text->n)-1] = (char *) malloc(20 * sizeof(char));
		(text->palavras)[(text->n)-1] = le_palavra(fp);/*tem que liberar da heap depois*/	
	}
	//printf("leu todo o texto na função\n");	
	return text;		
}

/* função ordena_palavras: utiliza o algoritmo de 'insertion sort' para ordenar um vetor de strings(usando strcmp(ordem lexicográfica));
 * @Parâmetros:
 * - um vetor de strings;
 * - um inteiro que representa a quantidade de palavras;	
 * 
 * @retorno:
 * - uma string com a palavra lida;
 * */
void ordena_palavras(char **vet, int n){
	int i=0, j;
	char chave[20];
	while(i < n){
		/*chave = vet[i]*/	
		strcpy(chave, vet[i]);
		j = i - 1;
		while(j >= 0 && strcmp(chave, vet[j]) < 0){
			strcpy(vet[j+1] , vet[j]);	
			j--;
		}
		strcpy(vet[j+1], chave);
		i++;
	}
}

int irmaos(char **vet, char *string, int pos, int *depois){
	int i = 0;
	int pos_or = pos;
	char *original = vet[pos];
	while(strcmp(original, vet[pos]) == 0){
		i++;	//depois tem que fazer i-1
		pos++;
		(*depois)++;
	}
	while(strcmp(original, vet[pos_or]) == 0){
		i++;	//depois tem que fazer i-1
		pos_or--;
	}
	//i-2
	if(DEBUG){
		printf("irmaos deu certo\n");	
	}
	return (i-1);	
}	

int busca_binaria(char **vet, char *string, int ini, int fim){
	int centro = (int)((ini+fim)/2);
	if(DEBUG){
		printf("%d\n", centro);
		printf("%s\n", vet[centro]);
		printf("%s\n", string);
		printf("str = %d\n", strcmp(vet[centro], string));		
	}
	if(strcmp(vet[centro], string) == 0) return centro;
	else{
		if(strcmp(vet[centro], string) > 0){
			return busca_binaria(vet, string, ini, centro-1);	
		}
		else{
			return busca_binaria(vet, string, centro+1, fim);	
		}	
	}
}

void resposta_final(char **vet, char *string, int n){
	int pos = busca_binaria(vet, string, 0, n);
	int depois = 0;
	if(DEBUG){
		printf("deu certo bb\n");	
	}
	int qtd = irmaos(vet, string, pos, &depois);
	printf("%s %d %s %s %s\n", string, qtd, vet[pos+(depois)], vet[pos+(depois+1)], vet[pos+(depois+2)]);
}

int main(int argc, char *argv[]){
	/*abertura do arquivo com a leitura do nome*/
	char nome[100];
	int i;
	scanf("%s", nome);
	//printf("%s", nome);
	FILE *fp;
	if((fp = fopen(nome, "r+")) == NULL){
		printf("erro ao abrir arquivo de leitura\n");
		return 1;	
	}
	//if(DEBUG) printf("abriu o arquivo\n");
	/*processo de leitura de todas as palavras do texto para ordená-las posteriormente*/
	TEXTO *text;
	text = texto_scanner(fp); /* retorna TEXTO* */
	if(DEBUG){
		printf("leu todo o texto e guardou na struct\n");	
	}
	/*hora de ordenar o vetor de palavras:*/
	ordena_palavras(text->palavras, text->n);
	/*for(i=0; i<(text->n); i++){
		printf("%s\n", (text->palavras)[i]);
	}*/
	/*leitura das palavras procuradas(CHAVES)*/
	int N;
	scanf("%d", &N);
	//printf("enezao = %d\n", N);
	char *chaves[N];
	for(i=0; i<N; i++){
		/*fgets(chaves[i], 20, stdin);	
		chaves[i][strlen(chaves[i]) - 1] = '\0';*/
		chaves[i] = le_palavra(stdin);
		resposta_final(text->palavras ,chaves[i], text->n);
		if(DEBUG){
			printf("respondeu, finalmente\n");	
		}
		//printf("%s\n", chaves[i]); 
		free(chaves[i]);
	}
    
    
    /*liberação de memória e de arquivo de leitura*/
	free(text->palavras);
	for(i=0; i<(text->n); i++) free((text->palavras)[i]);
	free(text);		
	fclose(fp);
	return 0;
}
