/*                          Tarefa 06
 *
 *    Este programa le os dados do winterGames.csv
 *    organiza em uma estrutuda de dados dentro de nós
 *             que sao ordenados em uma fila
 *    e apresenta os dados organizados na tela na maim.c.
 *
 */


#include <stdio.h>
#include <stdlib.h>

#include "dados.h"
#include "fila.h"

int main(){

   fila_t *fila = ler_dados("winterGames.csv");

    // Imprima os dados:
    print_dados(fila);

    // liberar_dados:
    libera_dados(fila);


    return 0;
}
