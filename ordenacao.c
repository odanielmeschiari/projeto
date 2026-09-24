// implementação das funções de ordenação

#include "ordenacao.h"
#include "horario.h"
#include "celula.h"

#include <stdio.h>
#include <stdlib.h>

// funcao insertion sort para ordenar poucos elementos
void insertion_sort(int n, celula **vet, int criterio){
	if (criterio == 2){ // prioridade
		// colocar cada termo, a partir do segundo, na posicao correta
		for (int i = 1; i<n; i++){
			int j = i-1;
			celula *temp = vet[i];
			int atual = celula_get_prior(temp);
			while ((j >= 0) && (atual > celula_get_prior(vet[j]))){
				vet[j+1] = vet[j];
				j--;
			}
			vet[j+1] = temp;
		}
	}
	else{ // tempo
	// colocar cada termo, a partir do segundo, na posicao correta
		for (int i = 1; i<n; i++){
			int j = i-1;
			celula *temp = vet[i];
			int atual = tempo_abs(celula_get_horario(temp));
			while ((j >= 0) && (atual < tempo_abs(celula_get_horario(vet[j])))){
				vet[j+1] = vet[j];
				j--;
			}
			vet[j+1] = temp;
		}
	}
	return;
}

// função auxiliar para o merge sort: não incluída na interface
void intercala(int esq, int dir, celula **vet_esq, celula **vet_dir, int n, celula **vet, int criterio){
	if (criterio == 2){ // prioridade
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
			if (celula_get_prior(vet_esq[aux_esq]) >= celula_get_prior(vet_dir[aux_dir])){
				vet[i] = vet_esq[aux_esq];
				aux_esq++;
			}
			else if (celula_get_prior(vet_esq[aux_esq]) < celula_get_prior(vet_dir[aux_dir])){
				vet[i] = vet_dir[aux_dir];
				aux_dir++;
			}
		}
		return;
	}
	else{ // tempo
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
			if (tempo_abs(celula_get_horario(vet_esq[aux_esq])) <= tempo_abs(celula_get_horario(vet_dir[aux_dir]))){
				vet[i] = vet_esq[aux_esq];
				aux_esq++;
			}
			else if (tempo_abs(celula_get_horario(vet_esq[aux_esq])) > tempo_abs(celula_get_horario(vet_dir[aux_dir]))){
				vet[i] = vet_dir[aux_dir];
				aux_dir++;
			}
		}
		return;
	}
}

// funcao merge sort para ordenar muitos elementos
void merge_sort(int n, celula **vet, int criterio){
	// caso base: acabaram os termos
	if (n <= 1) return;
	// dividir o vetor
	// esquerda
	int esq = n/2;
	celula *vet_esq[esq]; // 0 1 2 3 4 -> meio = 2, elemento meio = 2, quantidade esq = 3 (n/2+1), quantidade dir = 2 (n-esq)
	for (int i = 0; i<esq; i++){
		vet_esq[i] = vet[i];
	}
	// direita
	int dir = n-esq;
	celula *vet_dir[dir];
	for (int i = 0; i<dir; i++){
		vet_dir[i] = vet[esq+i];
	}
	// chamadas recursivas
	merge_sort(esq,vet_esq,criterio);
	merge_sort(dir,vet_dir,criterio);
	// por fim, intercalar ambos os vetores
	intercala(esq,dir,vet_esq,vet_dir,n,vet,criterio);
	return;
}

// função que ordena uma lista
void ordenar(int tam, celula **celulas, int criterio){
	if (tam <= 10){
		insertion_sort(tam,celulas,criterio);
	}
	else
		merge_sort(tam,celulas,criterio);
	return;
}
