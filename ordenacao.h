// esta interface contém os métodos de ordenação usados no projeto

#ifndef ORDENACAO_H
#define ORDENACAO_H

// nota: esta TAD ordena apenas vetores de inteiros. adaptar a main() para isso

// ordenação para poucos elementos
void insertion_sort(int n, int *vet);
// ordenação para muitos elementos
void merge_sort(int n, int *vet);

#endif
