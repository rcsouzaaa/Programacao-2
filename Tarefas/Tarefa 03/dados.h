/*                          Tarefa 03
 *
 *    Este programa le os dados do winterGames.csv de forma modularizada,
 *    aloca a memoria necessaria para armazena dentro de uma struct em dados.c
 *    e apresenta os dados organizados na tela na maim.c.
 *
 */

#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED


// Criação de tipo abstrato dado_t
typedef struct jogosIverno dado_t;
dado_t *cria_dado (int pos, char *nome, int ouro, int prata, int bronze, int total_med);
dado_t **ler_arquivo(char *nome_arquivo, int *tamanho);
void libera_dados(dado_t **paises,int tamanho);
void imprime_dados(dado_t **paises, int tamanho);

#endif // JOGOS_H_INCLUDED

