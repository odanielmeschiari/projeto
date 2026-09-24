// implementação do horário

#include "horario.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct HORARIO{
	int hh;
	int mm;
	int ss;
};

// funcao auxiliar que calcula o tempo absoluto
int tempo_abs(horario *horario){
	return horario->hh*3600 + horario->mm*60 + horario->ss; 
}

// funcao que cria um horario
horario *horario_criar(int hh, int mm, int ss){
	if (hh < 0 || mm < 0 || ss < 0) return NULL;
	horario *novo = (horario *)malloc(sizeof(horario));
	if (novo == NULL) return NULL;
	novo->hh = hh;
	novo->mm = mm;
	novo->ss = ss;
	return novo;
}

// funcao que apaga um horario
void horario_apagar(horario **x){
	if (x == NULL || *x == NULL) return;
	free(*x);
	*x = NULL;
	return;
}

// funcao que muda um horario dado
bool horario_change(horario *anterior, horario **novo){
	if (anterior == NULL || novo == NULL || *novo == NULL || anterior == (*novo)) return false;
	anterior->hh = (*novo)->hh;
	anterior->mm = (*novo)->mm;
	anterior->ss = (*novo)->ss;
	free(*novo);
	(*novo) = NULL;
	return true;
}

// funcao que imprime um horario
void horario_imprimir(horario *x){
	if (x == NULL) return;
	printf("%02d:%02d:%02d",x->hh,x->mm,x->ss);
	return;
}
