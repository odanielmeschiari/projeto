// lista sequencial expansível linear semiordenada

#include "lista.h"
#include "celula.h"
#include "horario.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1

struct lista{
	int ordem;
	int tamanho;
	int alocado;
	int inicio;
	int fim;
	celula **celulas;
};

// essa funcao cria uma lista
LISTA *lista_criar(void){
	LISTA *nova = (LISTA *)malloc(sizeof(LISTA));
	if (nova == NULL) return NULL;
	nova->ordem = 0;
	nova->tamanho = 0;
	nova->alocado = MAX;
	nova->inicio = 0;
	nova->fim = 0;
	// alocar o vetor de celulas
	celula **celulas = (celula **)calloc(MAX,sizeof(celula *));
	if (celulas == NULL) return NULL;
	nova->celulas = celulas;
	return nova;
}

// essa funcao apaga uma lista
void lista_apagar(LISTA **lista){
	if (lista == NULL || *lista == NULL) return;
	while ((*lista)->tamanho > 0){
		// apagar celula a celula
		apagar_celula(&(*lista)->celulas[(*lista)->tamanho-1]);
		(*lista)->tamanho--;
	}
	// apagar o vetor de ponteiros
	free((*lista)->celulas);
	// apagar a lista toda
	free(*lista);
	*lista = NULL;
	return;
}

// essa funcao insere um elemento no final da lista
bool lista_inserir(LISTA *lista, celula *item){
	if (lista == NULL || item == NULL) return false;
	if (lista->tamanho >= lista->alocado){
		celula **temp = (celula **) realloc(lista->celulas,sizeof(celula*)*(lista->alocado*2));
		if (temp == NULL) return false;
		lista->celulas = temp;
		lista->alocado *= 2;
	}
	// colocar no final
	lista->celulas[lista->fim++] = item;
	lista->tamanho++;
	lista->ordem = 0;
	return true;
}

// essa funcao remove o primeiro item da lista
celula *lista_remover(LISTA *lista){
	if (lista == NULL || lista->tamanho == 0) return NULL;
	celula *removida = lista->celulas[lista->inicio];
	// deslocar os elementos para cobrir o espaço movido
	for (int i = lista->inicio; i<lista->tamanho-1; i++){
		lista->celulas[i] = lista->celulas[i+1];
	}
	lista->tamanho--;
	lista->celulas[lista->tamanho] = NULL;
	lista->fim--;
	return removida;
}

// essa funcao mostra o próximo processo da lista sem remover
celula *lista_proximo(LISTA *lista){
	if (lista == NULL) return NULL;
	return lista->celulas[lista->inicio];
}

// essa funcao imprime a lista segundo um criterio
void imprimir_lista(LISTA *lista){
	if (lista == NULL) return;
	int cont = 0;
	while (cont < lista->tamanho){
		imprimir_celula(lista->celulas[cont++]);
	}
	return;
}

// essa funcao retorna a ordenacao atual da lista
int lista_get_ordem(LISTA *lista){
	if (lista == NULL) return -1;
	return lista->ordem;
}

// essa funcao muda a ordem da lista
bool lista_set_ordem(LISTA *lista, int ordem){
	if (lista == NULL || lista->ordem == ordem) return false;
	lista->ordem = ordem;
	return true;
}

// essa funcao retorna o tamanho atual da lista
int lista_tam(LISTA *lista){
	if (lista == NULL) return -1;
	return lista->tamanho;
}

// essa funcao retorna um ponteiro para as celulas da lista
celula **lista_celulas(LISTA *lista){
	if (lista == NULL) return NULL;
	return lista->celulas;
}
