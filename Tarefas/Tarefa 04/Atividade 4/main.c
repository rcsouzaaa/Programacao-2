/*                          Tarefa 04
 *
 *    Este programa le os dados do winterGames.csv
 *    organiza em uma estrutuda de dados dentro de nós
 *    que sao ordenados em uma lista encadeada
 *    e apresenta os dados organizados na tela na maim.c.
 *
 */


#include <stdio.h>
#include "dados.h"


int main(){

    lista_t *lista = ler_dados("winterGames.csv");

    // Imprima os dados:
    print_dados(lista);

    // liberar_dados:
    libera_dados(lista);

    return 0;
}
