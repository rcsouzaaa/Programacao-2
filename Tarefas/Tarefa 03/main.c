/*                          Tarefa 03
 *
 *    Este programa le os dados do winterGames.csv de forma modularizada,
 *    aloca a memoria necessaria para armazena dentro de uma struct em dados.c
 *    e apresenta os dados organizados na tela na maim.c.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dados.h"


int main()
{
    dado_t **lista;
    int tamanho;

    // chama funcao para ler arquivo
    lista = ler_arquivo("winterGames.csv", &tamanho);

    // chama funcao para imprimir os dados
    imprime_dados(lista,tamanho);

    // chama a funcao para liberar os dados
    libera_dados(lista,tamanho);

    return 0;
}
