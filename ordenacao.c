// implementação das funções de ordenação

#include "lista.h"
#include "ordenacao.h"
#include "horario.h"

#include <stdio.h>
#include <stdlib.h>

// funcao insertion sort para ordenar poucos elementos
void insertion_sort(int n, celula *vet, char criterio){
	if (criterio == 'p'){
		// colocar cada termo, a partir do segundo, na posicao correta
		for (int i = 1; i<n; i++){
			int j = i-1;
			celula temp = vet[i];
			int atual = temp->prior;
			while ((j >= 0) && (atual > vet[j]->prior)){
				vet[j+1] = vet[j];
				j--;
			}
			vet[j+1] = temp;
		}
	}
	else{
	// colocar cada termo, a partir do segundo, na posicao correta
		for (int i = 1; i<n; i++){
			int j = i-1;
			celula temp = vet[i];
			int atual = tempo_abs(temp->horario);
			while ((j >= 0) && (atual < tempo_abs(vet[j]->horario))){
				vet[j+1] = vet[j];
				j--;
			}
			vet[j+1] = temp;
		}
	}
	return;
}

// função auxiliar para o merge sort: não incluída na interface
void intercala(int esq, int dir, celula *vet_esq, celula *vet_dir, int n, celula *vet, char criterio){
	if (criterio == 'p'){
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
			if (vet_esq[aux_esq]->prior >= vet_dir[aux_dir]->prior){
				vet[i] = vet_esq[aux_esq];
				aux_esq++;
			}
			else if (vet_esq[aux_esq]->prior < vet_dir[aux_dir]->prior){
				vet[i] = vet_dir[aux_dir];
				aux_dir++;
			}
		}
		return;
	}
	else{
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
			if (tempo_abs(vet_esq[aux_esq]->horario) <= tempo_abs(vet_dir[aux_dir]->horario)){
				vet[i] = vet_esq[aux_esq];
				aux_esq++;
			}
			else if (tempo_abs(vet_esq[aux_esq]->horario) > tempo_abs(vet_dir[aux_dir]->horario)){
				vet[i] = vet_dir[aux_dir];
				aux_dir++;
			}
		}
		return;
	}
}

// funcao merge sort para ordenar muitos elementos
void merge_sort(int n, celula *vet, char criterio){
	// caso base: acabaram os termos
	if (n <= 1) return;
	if (criterio == 'p'){
		// dividir o vetor
		// esquerda
		int esq = n/2;
		celula vet_esq[esq]; // 0 1 2 3 4 -> meio = 2, elemento meio = 2, quantidade esq = 3 (n/2+1), quantidade dir = 2 (n-esq)
		for (int i = 0; i<esq; i++){
			vet_esq[i] = vet[i];
		}
		// direita
		int dir = n-esq;
		celula vet_dir[dir];
		for (int i = 0; i<dir; i++){
			vet_dir[i] = vet[esq+i];
		}
		// chamadas recursivas
		merge_sort(esq,vet_esq,criterio);
		merge_sort(dir,vet_dir,criterio);
		// por fim, intercalar ambos os vetores
		intercala(esq,dir,vet_esq,vet_dir,n,vet,criterio);
	}
	else{
		// dividir o vetor
		// esquerda
		int esq = n/2;
		celula vet_esq[esq]; // 0 1 2 3 4 -> meio = 2, elemento meio = 2, quantidade esq = 3 (n/2+1), quantidade dir = 2 (n-esq)
		for (int i = 0; i<esq; i++){
			vet_esq[i] = vet[i];
		}
		// direita
		int dir = n-esq;
		celula vet_dir[dir];
		for (int i = 0; i<dir; i++){
			vet_dir[i] = vet[esq+i];
		}
		// chamadas recursivas
		merge_sort(esq,vet_esq,criterio);
		merge_sort(dir,vet_dir,criterio);
		// por fim, intercalar ambos os vetores
		intercala(esq,dir,vet_esq,vet_dir,n,vet,criterio);
	}
	return;
}

// função que ordena uma lista
void ordenar(int tam, LISTA *lista, char criterio){
	int novo_criterio;
	switch(criterio){
		case 'p': novo_criterio = 1;
			break;
		case 't': novo_criterio = 2;
			break;
		default: printf("Erro\n"); return;
			break;
	}
	// caso já esteja ordenada segundo o criterio, basta continuar
	if (novo_criterio == lista->ordenacao){
		return;
	}
	if (tam <= 25){
		insertion_sort(tam,lista->celulas,criterio);
	}
	else
		merge_sort(tam,lista->celulas,criterio);
	lista->ordenacao = novo_criterio;
	return;
}
