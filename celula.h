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
// função que muda uma prioridade
void celula_set_prior(celula *x, int nova);
// função que obtém um horário
horario *celula_get_horario(celula *x);
// função que muda um horário
void celula_set_horario(celula *x, horario *novo);
// função que imprime uma célula
void imprimir_celula(celula *x);

#endif
