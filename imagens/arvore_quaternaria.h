#ifndef ARVORE_QUATERNARIA
#define ARVORE_QUATERNARIA 

typedef struct arvore ARVORE;
typedef struct no NO;
	
ARVORE *criar_arvore();
NO *criar_no();
NO *criar_no_lendo();
void montar_arvore(ARVORE *T);
NO *montar_no(ARVORE *T);
//void inserir_raiz(ARVORE *T, char estado);
//void inserir_no(ARVORE *T, char estado);
void apagar_arvore(ARVORE *T);
void apagar_no(NO *node);	
ARVORE *sobreposicao_de_arvores();
NO *sobreposicao_de_nos(NO *n1, NO *n2);
int pixels_pretos(ARVORE *T);
void contar_pp(NO *node, int *pp, int *nivel);
void imprimir_arvore(ARVORE *T);
void imprimir_no(NO *node);

#endif