#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

#include "no.h"

typedef struct listas_enc lista_t;


lista_t *cria_lista_enc(void);

void add_cauda(lista_t *lista, no_t* elemento);

no_t *obter_cabeca(lista_t *lista);

void add_cabeca(lista_t *lista, no_t* elemento);

void *remove_cabeca (lista_t *lista);

void *remove_cauda (lista_t *lista);

void print_lista(lista_t *lista);

int tamanho_lista(lista_t *lista);

int lista_vazia(lista_t *lista);

no_t * obtem_cabeca(lista_t *lista);

#endif // LISTA_ENC_H_INCLUDED
