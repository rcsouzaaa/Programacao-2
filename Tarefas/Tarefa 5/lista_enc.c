#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

/* #define DEBUG */

struct listas_enc {
    no_t *cabeca;   /*!< Referência da cabeça da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Referência da cauda da lista encadeada: último elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

//cria uma lista vazia

lista_t *cria_lista_enc (void) {
    lista_t *p = malloc(sizeof(lista_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}


void add_cauda(lista_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desliga_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desliga_no(elemento);
        // Liga cauda da lista com novo elemento
        liga_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}


void add_cabeca(lista_t *lista, no_t* elemento)
{
	if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
	}

	#ifdef DEBUG
	printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
	#endif // DEBUG

	//lista vazia
	if (lista->tamanho == 0)
	{
        #ifdef DEBUG
        printf("add_cabeca: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cabeca = elemento;
        lista->cauda= elemento;
        lista->tamanho++;

        desliga_no(elemento);
	}
	else {
        // Remove qualquer ligacao antiga
        desliga_no(elemento);
        // Liga cauda da lista com novo elemento
        liga_nos(elemento, lista->cabeca);

        lista->cabeca = elemento;
        lista->tamanho++;
	}
}

void *remove_cabeca (lista_t *lista)
{
	if (lista->tamanho==0)
		printf("nao ha nos ");

	no_t *elemento;
	no_t *proximo;
	elemento=lista->cabeca;
	proximo=obtem_proximo(elemento);
	desliga_no(elemento);
	lista->cabeca=proximo;
	lista->tamanho--;

	if(elemento == NULL)
        return NULL;

    return elemento;
}

void *remove_cauda (lista_t *lista)
{
	if (lista->tamanho==0)
		printf("nao ha nos ");

	no_t *elemento;
	elemento=lista->cauda;
	desliga_no(elemento);
	lista->cauda=NULL;
	lista->tamanho--;

	if(elemento == NULL)
        return NULL;

    return elemento;
}

void print_lista(lista_t *lista)
{
	no_t *elemento = obtem_cabeca(lista);

	int i;

	for (i=0; i<lista->tamanho; i++)
	{
		printf("%d, %s\n", i,(char*)obtem_dado(elemento));
		elemento=obtem_proximo(elemento);
	}
}

int tamanho_lista(lista_t *lista)
{
	return lista->tamanho;
}

int lista_vazia(lista_t *lista)
{
	if (lista == NULL)
	{
        fprintf(stderr,"Ponteiro de lista nulo ");
        exit(EXIT_FAILURE);
	}

	if (lista->tamanho==0)
	{
		printf("lista vazia");
		return 0;
	}
	else{
		return 1;
	}
}

no_t * obtem_cabeca(lista_t *lista)
{
	return lista -> cabeca;
}

