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
celula *lista_remover(LISTA *lista, int criterio);
// essa funcao mostra o próximo processo da lista sem remover
celula *lista_proximo(LISTA *lista, int criterio);
// essa funcao muda um campo "horario" de uma celula
bool lista_change_horario(LISTA *lista, horario *anterior, horario *novo);
// essa funcao muda um campo "prior" de uma celula
bool lista_change_prior(LISTA *lista, int prior_anterior, int prior_novo);
// essa funcao imprime a lista segundo um criterio
void imprimir_lista(LISTA *lista, int criterio);

#endif