#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "horario.h"
#include "celula.h"
#include "lista.h"

#define CRITERIO_TEMPO 1
#define CRITERIO_PRIORIDADE 2

int main(void) {
    LISTA *lista = lista_criar();
    char comando[7];

    while (1) {
        scanf("%s", comando);
        if (strcmp(comando, "quit") == 0) {
            break;
        }

        //add prior tempo descrição (vo botar só o nome do jeito q é pra ser chamado cada operação p eu me organinzar ainda facilita pro Adylson )
        if (strcmp(comando, "add") == 0) {
            int prior, hh, mm, ss;
            char descricao[51];

            scanf("%d %d:%d:%d %s", &prior, &hh, &mm, &ss, descricao); //fiz assim pq diz o dani q funciona (o %d:%d:%d)

            horario *h = horario_criar(hh, mm, ss);
            celula *c = criar_celula(prior, h, descricao);

            lista_inserir(lista, c);
        }

        //exec (-t é 1, -p e 2)
        else if (strcmp(comando, "exec") == 0) {
            char opcao[3];
            scanf("%s", opcao);

            int criterio;
            if (strcmp(opcao, "-t") == 0) {
                criterio = CRITERIO_TEMPO;
            } else if (strcmp(opcao, "-p") == 0){
                criterio = CRITERIO_PRIORIDADE;
            }
            //como enzo disse q NULL é a saida padrao pra se der errado isso verifica se o endereço é válido 
            celula *removida = lista_remover(lista, criterio);
            if (removida != NULL) {
                apagar_celula(&removida);
            }
        }

        //next (-t é 1, -p é 2)
        else if (strcmp(comando, "next") == 0) {
            char opcao[3];
            scanf("%s", opcao);

            int criterio;
            if (strcmp(opcao, "-t") == 0) {
                criterio = CRITERIO_TEMPO;
            } else if (strcmp(opcao, "-p") == 0){
                criterio = CRITERIO_PRIORIDADE;
            }

            celula *prox = lista_proximo(lista, criterio);
            if (prox != NULL) {
                imprimir_celula(prox);
            }
        }

        //change
        else if (strcmp(comando, "change") == 0) {
            char opcao[3];
            scanf("%s", opcao);

            if (strcmp(opcao, "-p") == 0) {
                int anterior, novo;
                scanf("%d|%d", &anterior, &novo);
                lista_change_prior(lista, anterior, novo);
            } 
            else if (strcmp(opcao, "-t") == 0) {
                int h1, m1, s1, h2, m2, s2;
                scanf("%d:%d:%d|%d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

                horario *h_anterior = horario_criar(h1, m1, s1);
                horario *h_novo = horario_criar(h2, m2, s2);

                lista_change_horario(lista, h_anterior, h_novo);

                horario_apagar(&h_anterior);
                horario_apagar(&h_novo);
            }
        }

        //print (-t é 1, -p é 2)
        else if (strcmp(comando, "print") == 0) {
            char opcao[3];
            scanf("%s", opcao);

            int criterio;
            if (strcmp(opcao, "-t") == 0) {
                criterio = CRITERIO_TEMPO;
            } else if (strcmp(opcao, "-p") == 0){
                criterio = CRITERIO_PRIORIDADE;
            }

            imprimir_lista(lista, criterio);
        }
    }

    lista_apagar(&lista);

    return 0;
}
