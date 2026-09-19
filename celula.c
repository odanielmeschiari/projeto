// definições das funções na interface celula_.h

#include "celula.h"
#include "horario.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>

#define MAX_DESCR 50

struct celula_{
	int prior;
	horario *chegada;
	char descricao[MAX_DESCR];
};

// funcao criar celula_
celula *criar_celula(int prior, horario *horario, char *descricao){
	celula *x = (celula *)malloc(sizeof(celula));
	if (x == NULL)
		return NULL;
	x->prior = prior;
	celula->chegada = horario;
	celula->descricao = descricao;
	return x;
}

// funcao apagar celula_
void apagar_celula(celula **x){
	if (x == NULL || *x == NULL)
		return;
	horario_apagar(horario *x->chegada);
	free(*x);
	*x = NULL;
	return;
}

// funcao get prior
int celula_get_prior(celula *x){
	return x->prior;
}

// funcao get horario
horario *celula_get_horario(celula *x){
	if (x == NULL) return NULL;
	return x->chegada;
}

// funcao imprimir celula
void imprimir_celula(celula *x){
	if (x == NULL) return;
	printf("%d ",x->prior);
	horario_imprimir(x->chegada);
	printf("%s\n",x->descricao);
	return;
}