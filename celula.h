// interface da célula

#ifndef CELULA_H
#define CELULA_H

// inclusão da TAD horário
#include "horario.h"

// declaração da célula
typedef struct celula_ celula;

// função que cria uma célula dados os dados
celula *criar_celula(int prior, horario *horario, char *descricao);
// função que apaga uma célula
void apagar_celula(celula **x);
// função que obtém uma prioridade
int celula_get_prior(celula *x);
// função que obtém um horário
horario *celula_get_horario(celula *x);
// função que imprime uma célula
void imprimir_celula(celula *x);

#endif
