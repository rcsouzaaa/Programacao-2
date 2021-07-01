#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

#include "lista_enc.h"
#include "no.h"

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

lista_t * ler_dados(char *nome_do_arquivo);
dado_t *cria_dado(int pos,char *nome,int ouro,int prata,int bronze,int total_med);

void no_de_dados(lista_t *lista);
void print_dados(lista_t *lista);
void no_de_dados(lista_t *lista);

#endif
