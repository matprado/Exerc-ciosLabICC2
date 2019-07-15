#ifndef AVL2_H
#define AVL2_H
#include "fila.h"

#define max(a, b) ((a > b) ? a : b)

typedef struct avl AVL;
typedef struct No NO;

AVL *avl_criar(void);
void avl_apagar_aux(NO *raiz);
void avl_apagar(AVL **arvore);
int avl_altura_no(NO* raiz);
NO *avl_cria_no(int item);
NO *rodar_direita(NO *a);
NO *rodar_esquerda(NO *a);
NO *rodar_esquerda_direita(NO *a);
NO *rodar_esquerda_direita(NO *a);
NO *avl_inserir_no(NO *raiz, int item);
int avl_inserir(AVL *arvore, int item);
void pre_ordem(NO *raiz);
void em_ordem(NO *raiz);
void pos_ordem(NO *raiz);
void imprimir_largura(NO *raiz);
NO *AVL_raiz(AVL *T);
int esta_na_avl(NO *raiz, int item);

#endif