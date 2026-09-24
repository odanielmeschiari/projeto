// esta é a interface da lista

#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

#include "celula.h"
#include "horario.h"

// estrutura da lista
typedef struct lista LISTA;

// essa funcao cria uma lista
LISTA *lista_criar(void);
// essa funcao apaga uma lista
void lista_apagar(LISTA **lista);
// essa funcao insere um elemento no final da lista
bool lista_inserir(LISTA *lista, celula *item);
// essa funcao remove o primeiro item da lista segundo um critério
celula *lista_remover(LISTA *lista);
// essa funcao mostra o próximo processo da lista sem remover
celula *lista_proximo(LISTA *lista);
// essa funcao imprime a lista segundo um criterio
void imprimir_lista(LISTA *lista);
// essa funcao retorna a ordenacao atual da lista
int lista_get_ordem(LISTA *lista);
// essa funcao muda a ordem da lista
bool lista_set_ordem(LISTA *lista, int ordem);
// essa funcao retorna o tamanho atual da lista
int lista_tam(LISTA *lista);
// essa funcao retorna um ponteiro para as celulas da lista
celula **lista_celulas(LISTA *lista);

#endif
