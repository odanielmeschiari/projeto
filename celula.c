// definições das funções na interface celula_.h

#include "celula.h"
#include "horario.h"

#include <stdlib.h>
#include <stdio.h>
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
	x->chegada = horario;
	int i;
	for (i = 0; descricao[i] != '\0'; i++){
		x->descricao[i] = descricao[i];
	}
	x->descricao[i] = '\0';
	return x;
}

// funcao apagar celula_
void apagar_celula(celula **x){
	if (x == NULL || *x == NULL)
		return;
	horario_apagar(&((*x)->chegada));
	free(*x);
	*x = NULL;
	return;
}

// funcao get prior
int celula_get_prior(celula *x){
	return x->prior;
}

// função que muda uma prioridade
void celula_set_prior(celula *x, int nova){
	if (x == NULL) return;
	x->prior = nova;
	return;
}

// funcao get horario
horario *celula_get_horario(celula *x){
	if (x == NULL) return NULL;
	return x->chegada;
}

// função que muda um horário
void celula_set_horario(celula *x, horario *novo){
	if (x == NULL || novo == NULL) return;
	horario_change(x->chegada,&novo);
	return;
}

// funcao imprimir celula
void imprimir_celula(celula *x){
	if (x == NULL) return;
	printf("%d ",x->prior);
	horario_imprimir(x->chegada);
	printf(" %s\n",x->descricao);
	return;
}
