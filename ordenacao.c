// implementação das funções de ordenação

#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>

// funcao insertion sort para ordenar poucos elementos
void insertion_sort(int n, int *vet){
	// colocar cada termo, a partir do segundo, na posicao correta
	for (int i = 1; i<n; i++){
		int j = i-1;
		int atual = vet[i];
		while ((j >= 0) && (atual < vet[j])){
			vet[j+1] = vet[j];
			j--;
		}
		vet[j+1] = atual;
	}
	return;
}

// função auxiliar para o merge sort: não incluída na interface
void intercala(int esq, int dir, int *vet_esq, int *vet_dir, int n, int *vet){
	int aux_esq = 0;
	int aux_dir = 0;
	for (int i = 0; i<n; i++){
		// caso chegue ao final de um dos vetores, usar apenas o outro
		if (aux_esq == esq){
			while (i < n){
				vet[i++] = vet_dir[aux_dir++];
			}
			break;
		}
		else if (aux_dir == dir){
			while (i < n){
				vet[i++] = vet_esq[aux_esq++];
			}
			break;
		}
		// cada elemento deve receber o menor de ambos
		if (vet_esq[aux_esq] < vet_dir[aux_dir]){
			vet[i] = vet_esq[aux_esq];
			aux_esq++;
		}
		else if (vet_esq[aux_esq] >= vet_dir[aux_dir]){
			vet[i] = vet_dir[aux_dir];
			aux_dir++;
		}
	}
	return;
}

// funcao merge sort para ordenar muitos elementos
void merge_sort(int n, int *vet){
	// caso base 1: acabaram os termos
	if (n <= 1) return;
	// caso base 2: temos apenas 2 termos
	if (n == 2){
		if (vet[0] > vet[1]){
			// fazer a troca entre dois
			int temp = vet[0];
			vet[0] = vet[1];
			vet[1] = temp;
		}
		return;
	}
	// dividir o vetor
	// esquerda
	int esq = n/2+1;
	int vet_esq[esq]; // 0 1 2 3 4 -> meio = 2, elemento meio = 2, quantidade esq = 3 (n/2+1), quantidade dir = 2 (n-esq)
	for (int i = 0; i<esq; i++){
		vet_esq[i] = vet[i];
	}
	// direita
	int dir = n-esq;
	int vet_dir[dir];
	for (int i = 0; i<dir; i++){
		vet_dir[i] = vet[esq+i];
	}
	// chamadas recursivas
	merge_sort(esq,vet_esq);
	merge_sort(dir,vet_dir);
	// por fim, intercalar ambos os vetores
	intercala(esq,dir,vet_esq,vet_dir,n,vet);
	return;
}
