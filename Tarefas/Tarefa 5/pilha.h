#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "no.h"

typedef struct pilhas pilha_t;


pilha_t *cria_pilha(void);

no_t *obtem_pilha(pilha_t *lista);

void push(pilha_t *lista, no_t* elemento);

void *pop (pilha_t *lista);

void print_pilha(pilha_t *lista);

int tamanho_pilha(pilha_t *lista);

int pilha_vazia(pilha_t *lista);

no_t * obtem_pilha(pilha_t *lista);

#endif // PILHA_H_INCLUDED
