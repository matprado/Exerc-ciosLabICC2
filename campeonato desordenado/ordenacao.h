#ifndef ORDENACAO_H
#define ORDENACAO_H

#define TIPO int

void insertion_sort(TIPO *vet, int n);
//void bubble_sort(TIPO *vet, int n);
void merge_sort(TIPO *vet, int ini, int fim);
void merge(TIPO *vet, int ini, int meio, int fim);

#endif