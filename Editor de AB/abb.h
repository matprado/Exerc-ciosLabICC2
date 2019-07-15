#ifndef ABB_H
#define ABB_H

typedef struct No_ NO;
typedef struct abb ABB;

ABB *arv_criar(void);
int abb_inserir(ABB *T, int chave);
NO *abb_inserir_filho(int filho, NO *no, int chave);
int abb_inserir_no(NO *raiz, int chave);
int abb_busca(NO *raiz, int chave);
void troca_max_esq(NO *troca, NO *rem, NO *ant);
int abb_remover_aux(NO *raiz, NO *rem, NO *ant, int chave);
void pre_ordem(NO *raiz);
void em_ordem(NO *raiz);
void pos_ordem(NO *raiz);
void imprimir_largura(NO *raiz);
NO *ABB_raiz(ABB *T);
int chave_item(NO *i);
void troca_max_dir(NO *troca, NO *rem, NO *ant);


#endif