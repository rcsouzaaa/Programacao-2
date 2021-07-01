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
pilha_t *cria_pilha (void)
{
    pilha_t *p = malloc(sizeof(pilha_t));

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
void push(pilha_t *lista, no_t *elemento)
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
void *pop (pilha_t *lista)
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


void libera_pilha(pilha_t* pilha)
{
    free(pilha);
	pilha->topo = NULL;
	pilha->tam = 0;
}


int tamanho_pilha(pilha_t *pilha)
{
    return pilha->tam;
}

int pilha_vazia(pilha_t *pilha)
{
    if (pilha == NULL)
    {
        fprintf(stderr,"Ponteiro de pilha nulo ");
        exit(EXIT_FAILURE);
    }

    if (pilha->tam==0)
    {
        printf("pilha vazia");
        return 1;
    }
    else
    {
        return 0;
    }
}

no_t * obtem_pilha(pilha_t *pilha)
{
    return pilha->topo;
}
