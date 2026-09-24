// interface do horario

#ifndef HORARIO_H
#define HORARIO_H

#include <stdbool.h>

typedef struct HORARIO horario;

// funcao auxiliar que calcula o tempo absoluto
int tempo_abs(horario *horario);
// funcao que cria um horario
horario *horario_criar(int hh, int mm, int ss);
// funcao que apaga um horario
void horario_apagar(horario **x);
// funcao que muda um horario dado
bool horario_change(horario *anterior, horario **novo);
// funcao que imprime um horario
void horario_imprimir(horario *x);

#endif
