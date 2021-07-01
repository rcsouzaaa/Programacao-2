#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "pilha.h"


/* #define DEBUG */

struct pilhas
{
    no_t * topo;   /*!< Referência ao topo: primeiro elemento. */
    int tam;    /*!< tam atual da pilha. */
};

//cria uma pilha generica
dado_t *cria_pilha (void)
{
    dado_t *p = malloc(sizeof(dado_t));

    if (p == NULL)
    {
        perror("cria_pilha:");
        exit(EXIT_FAILURE);
    }

    p->topo = NULL;
    p->tam = 0;

    return p;
}

//adiciona elemento
void push(dado_t *lista, no_t *elemento)
{
    if (lista == NULL || elemento == NULL)
    {
        fprintf(stderr,"push: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

#ifdef DEBUG
    printf("Adicionando %p --- tam: %d\n", elemento, lista->tam);
#endif // DEBUG

    //lista vazia
    if (lista->tam == 0)
    {
#ifdef DEBUG
        printf("push: add primeiro elemento: %p\n", elemento);
#endif // DEBUG

        lista->topo = elemento;
        lista->tam++;
        desliga_no(elemento);
    }
    else
    {
        liga_nos(elemento,lista->topo);
        lista->topo = elemento;
        lista->tam++;
    }
}

//retira elemento do topo
void *pop (dado_t *lista)
{
    if (lista->tam==0)
    {
        printf("nao ha nos ");
        return 0;
    }

    lista->topo = obtem_proximo(lista->topo);
    lista->tam--;
    return 0;
}

void print_pilha(dado_t *lista)
{
    no_t *elemento = lista->topo;

    int i;

    for (i=0; i<lista->tam; i++)
    {
        printf("%d, %s\n", i,(char*)obtem_dado(elemento));
        elemento=obtem_proximo(elemento);
    }
}

void libera_pilha(dado_t* pilha)
{

    pilha->topo = NULL;
}


int tamanho_pilha(dado_t *lista)
{
    return lista->tam;
}

int pilha_vazia(dado_t *lista)
{
    if (lista == NULL)
    {
        fprintf(stderr,"Ponteiro de lista nulo ");
        exit(EXIT_FAILURE);
    }

    if (lista->tam==0)
    {
        printf("lista vazia");
        return 0;
    }
    else
    {
        return 1;
    }
}

no_t * obtem_pilha(dado_t *lista)
{
    return lista -> topo;
}

