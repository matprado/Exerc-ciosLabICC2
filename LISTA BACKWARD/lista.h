#ifndef LISTA_H
#define LISTA_H

#define ERRO -404
#define TIPO int
#define MAX 100
typedef struct lista LISTA;
typedef struct no NO;

LISTA *lista_criar(void);
void lista_apagar(LISTA *L);
//TIPO lista_buscar_item(LISTA *L, TIPO chave);
NO *buscar_posicao(LISTA *L, int pos);
int lista_inserir_fim(LISTA *L, int tempo, int chave, int j); /*INSERE NA ÚLTIMA POSIÇÃO*/
void atualizar_backs(LISTA *L, NO *aux_remocao);
int lista_remover_item(LISTA *L, int chave);
int posicao(LISTA *L, NO* x);
void lista_imprimir(LISTA *L);
int lista_vazia(LISTA *L);
int lista_tamanho(LISTA *L);

#endif