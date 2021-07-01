#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "no.h"

typedef struct pilhas dado_t;


dado_t *cria_pilha(void);

no_t *obtem_pilha(dado_t *lista);

void push(dado_t *lista, no_t* elemento);

void *pop (dado_t *lista);

void print_pilha(dado_t *lista);

int tamanho_pilha(dado_t *lista);

int pilha_vazia(dado_t *lista);

no_t * obtem_pilha(dado_t *lista);

#endif // PILHA_H_INCLUDED
