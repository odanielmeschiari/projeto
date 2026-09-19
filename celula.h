// interface da célula

#ifndef CELULA_H
#define CELULA_H

#include "horario.h"

typedef struct celula_ celula;

celula *criar_celula(int prior, horario *horario, char *descricao);
void apagar_celula(celula **x);
int celula_get_prior(celula *x);
horario *celula_get_horario(celula *x);
void imprimir_celula(celula *x);

#endif
