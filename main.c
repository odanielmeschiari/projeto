#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "horario.h"
#include "celula.h"
#include "lista.h"
#include "ordenacao.h"

#define CRITERIO_TEMPO 1
#define CRITERIO_PRIORIDADE 2

// essa funcao encontra a posicao pelo criterio prioridade
int busca_prior(int inicio, int fim, celula **celulas, int anterior){
    if (inicio > fim) return -1;

    int meio = (inicio + fim)/2;
    int atual = celula_get_prior(celulas[meio]);
    if (atual == anterior){
        // encontrados. retornar...
        return meio;
    }
    else if (atual < anterior){
        // nesse caso está à esquerda
        return busca_prior(inicio,meio-1,celulas,anterior);
    }
    else{
        // nesse caso está à direita
        return busca_prior(meio+1,fim,celulas,anterior);
    }
}

// essa funcao encontra a posicao pelo criterio horario
int busca_horario(int inicio, int fim, celula **celulas, horario *anterior){
    if (inicio > fim) return -1;

    int meio = (inicio + fim)/2;
    horario *atual = celula_get_horario(celulas[meio]);
    if (tempo_abs(atual) == tempo_abs(anterior)){
        // encontrados. retornar...
        return meio;
    }
    else if (tempo_abs(atual) > tempo_abs(anterior)){
        // nesse caso está à esquerda
        return busca_horario(inicio,meio-1,celulas,anterior);
    }
    else{
        // nesse caso está à direita
        return busca_horario(meio+1,fim,celulas,anterior);
    }
}

int main(void) {
    LISTA *lista = lista_criar();
    char comando[7];

    while (1) {
        scanf("%s", comando);
        if (strcmp(comando, "quit") == 0) {
            break;
        }

        // add prior tempo descrição
        if (strcmp(comando, "add") == 0) {
            int prior, hh, mm, ss;
            char descricao[51];

            scanf("%d %d:%d:%d %s", &prior, &hh, &mm, &ss, descricao);

            horario *h = horario_criar(hh, mm, ss);
            celula *c = criar_celula(prior, h, descricao);

            lista_inserir(lista, c);
        }

        // exec (-t é 1, -p e 2)
        else if (strcmp(comando, "exec") == 0) {
            char opcao[3];
            scanf("%s", opcao);

            int criterio;
            if (strcmp(opcao, "-t") == 0) {
                criterio = CRITERIO_TEMPO;
            } else if (strcmp(opcao, "-p") == 0){
                criterio = CRITERIO_PRIORIDADE;
            }

            // verificar se precisa ordenar. se precisar, ordenar
            if (lista_get_ordem(lista) == criterio){
                celula *removida = lista_remover(lista);
                if (removida != NULL)
                    apagar_celula(&removida);
            }
            else{
                ordenar(lista_tam(lista),lista_celulas(lista),criterio);
                // mudar a ordem para a nova
                lista_set_ordem(lista,criterio);
                celula *removida = lista_remover(lista);
                if (removida != NULL)
                    apagar_celula(&removida);
            }
        }

        // next (-t é 1, -p é 2)
        else if (strcmp(comando, "next") == 0) {
            char opcao[3];
            scanf("%s", opcao);

            int criterio;
            if (strcmp(opcao, "-t") == 0) {
                criterio = CRITERIO_TEMPO;
            } else if (strcmp(opcao, "-p") == 0){
                criterio = CRITERIO_PRIORIDADE;
            }

            // verificar se precisa ordenar. se precisar, ordenar
            if (lista_get_ordem(lista) == criterio){
                celula *next = lista_proximo(lista);
                imprimir_celula(next);
            }
            else{
                ordenar(lista_tam(lista),lista_celulas(lista),criterio);
                // mudar a ordem para a nova
                lista_set_ordem(lista,criterio);
                celula *next = lista_proximo(lista);
                imprimir_celula(next);
            }
            printf("\n");
        }

        // change
        else if (strcmp(comando, "change") == 0) {
            char opcao[3];
            scanf("%s", opcao);

            int criterio;
            if (strcmp(opcao, "-t") == 0) {
                criterio = CRITERIO_TEMPO;
            } else if (strcmp(opcao, "-p") == 0){
                criterio = CRITERIO_PRIORIDADE;
            }

            if (strcmp(opcao, "-p") == 0) {
                int anterior, novo;
                scanf("%d|%d", &anterior, &novo);
                // checar ordenação
                if (lista_get_ordem(lista) != criterio){
                    ordenar(lista_tam(lista),lista_celulas(lista),criterio);
                    // mudar a ordem para a nova
                    lista_set_ordem(lista,criterio);
                }
                // encontrar a posicao correta na lista
                celula **celulas = lista_celulas(lista);
                int pos = busca_prior(0,lista_tam(lista)-1,celulas,anterior);
                // com a posicao, basta alterar
                if (pos != -1) celula_set_prior(celulas[pos],novo);
            } 
            else if (strcmp(opcao, "-t") == 0) {
                int h1, m1, s1, h2, m2, s2;
                scanf("%d:%d:%d|%d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

                // checar ordenação
                if (lista_get_ordem(lista) != criterio){
                    ordenar(lista_tam(lista),lista_celulas(lista),criterio);
                    // mudar a ordem para a nova
                    lista_set_ordem(lista,criterio);
                }

                horario *h_anterior = horario_criar(h1, m1, s1);
                horario *h_novo = horario_criar(h2, m2, s2);

                // encontrar a posicao correta na lista
                celula **celulas = lista_celulas(lista);
                int pos = busca_horario(0,lista_tam(lista)-1,celulas,h_anterior);
                // com a posicao, basta alterar
                if (pos != -1) celula_set_horario(celulas[pos],h_novo);

                horario_apagar(&h_anterior);
            }
            // resetar ordenacao
            lista_set_ordem(lista,0);
        }

        // print (-t é 1, -p é 2)
        else if (strcmp(comando, "print") == 0) {
            char opcao[3];
            scanf("%s", opcao);

            int criterio;
            if (strcmp(opcao, "-t") == 0) {
                criterio = CRITERIO_TEMPO;
            } else if (strcmp(opcao, "-p") == 0){
                criterio = CRITERIO_PRIORIDADE;
            }

            // checar ordenação
            if (lista_get_ordem(lista) != criterio){
                ordenar(lista_tam(lista),lista_celulas(lista),criterio);
                // mudar a ordem para a nova
                lista_set_ordem(lista,criterio);
            }

            imprimir_lista(lista);
            printf("\n");
        }
    }

    lista_apagar(&lista);

    return 0;
}
