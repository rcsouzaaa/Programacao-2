#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"

#define FALSO 0
#define VERDADEIRO 1

struct filas
{
    //lista_enc_t *dados;
    no_t *inicio;
    no_t *fim;
    int tamanho_fila;
};

//cria uma fila generica
fila_t * cria_fila (void)
{
    fila_t *p = malloc(sizeof(fila_t));

    if (p == NULL)
    {
        perror("fila_t:");
        exit(EXIT_FAILURE);
    }

    p->inicio = NULL;
    p->fim = NULL;
    p->tamanho_fila = 0;

    return p;
}

//adiciona dado
void enqueue(void* dado, fila_t *fila)
{

    if (fila == NULL || dado == NULL)
    {
        fprintf(stderr,"enqueue: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    //fila vazia
    if (fila->tamanho_fila == 0)
    {
        fila->inicio = dado;
        fila->fim = dado;
        fila->tamanho_fila++;
        desliga_no(dado);
    }
    else
    {
        /*liga_nos(dado,fila->fim);
        fila->inicio = dado;
        fila->tamanho_fila++;*/

        liga_nos(fila->fim,dado);
        fila->fim = dado;
        fila->tamanho_fila++;

    }

}

//retira dado do inicio
void *dequeue(fila_t *fila)
{

    if (fila->tamanho_fila==0)
    {
        printf("nao ha nos ");
        return 0;
    }

    fila->inicio = obtem_proximo(fila->inicio);
    fila->tamanho_fila--;
    return 0;//retorno da fila em vez de 0

}

void libera_fila(fila_t* fila)
{
    free(fila);
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho_fila = 0;
}

int fila_vazia(fila_t *fila)
{
    if (fila == NULL)
    {
        fprintf(stderr,"Ponteiro de fila nulo ");
        exit(EXIT_FAILURE);
    }

    if (fila->tamanho_fila == 0)
    {
        printf("fila vazia");
        return 1;
    }
    return 0;
}

no_t * obtem_fila(fila_t *fila)
{
    return fila->inicio;
}

int tamanho_fila(fila_t *fila)
{
    return fila->tamanho_fila;
}

