#include <stdio.h>
#include <stdlib.h>


#include "no.h"

struct nos{
    void* dados;    /*!< Referência do dado respectiva ao nó da lista encadeada. */
    no_t *proximo;  /*!< Referência do próximo elemento da lista encadeada. */
};


no_t *cria_no(void *dado)
{
    no_t *p = malloc(sizeof(no_t));

    if (p == NULL){
        perror("cria_no:");
        exit(EXIT_FAILURE);
    }

    p->dados = dado;
    p->proximo = NULL;

    return p;
}


void liga_nos (no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL){
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    fonte->proximo = destino;
}


void desliga_no (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"desligar_no: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
}


void *obtem_dado (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"obter_dado: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->dados;
}


no_t *obtem_proximo (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"obter_proximo: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->proximo;
}
