#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

#include "no.h"
#include "fila.h"
/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

fila_t * ler_dados(char *nome_do_arquivo);
dado_t *cria_dado(int pos,char *nome,int ouro,int prata,int bronze,int total_med);

void no_de_dados(fila_t *lista);
void print_dados(fila_t *lista);
void no_de_dados(fila_t *lista);

#endif
