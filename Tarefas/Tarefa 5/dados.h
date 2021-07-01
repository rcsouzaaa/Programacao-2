#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

#include "no.h"
#include "pilha.h"
/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

pilha_t * ler_dados(char *nome_do_arquivo);
dado_t *cria_dado(int pos,char *nome,int ouro,int prata,int bronze,int total_med);

void no_de_dados(pilha_t *lista);
void print_dados(pilha_t *lista);
void no_de_dados(pilha_t *lista);

#endif
