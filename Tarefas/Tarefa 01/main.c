/** Programa exemplo que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  *
  *         Cabeçalho
  *         <string>;<int>;<char>
  *         <string>;<int>;<char>
  *
  * Altere conforme o CSV da atividade.
  *
  */

#include <stdio.h>  /* Para fgets, fscanf, ... */
#include <stdlib.h> /* Para exit, malloc, ... */

#define TAM_BUFFER 128

int main()
{
    /* Tipos das colunas do arquivo */
    char linha[TAM_BUFFER];
    char nome[TAM_BUFFER];
    int posisao, ouro, prata, bronze, total;

    // abre arquivo
    FILE *fp = fopen("winterGames.csv","r");

    // Imprime erro e aborta caso nao encontre conteudo
    if (fp == NULL)
    {
        perror("Erro em main: fopen");
        exit(EXIT_FAILURE);
    }

    // Cabecalho
    fgets(linha,128,fp);
    printf("Cabecalho: %s", linha);

    // Utilizando a construção do fscanf para ler o arquivo e complete abaixo
    //while só termina quando não for mais possível converter nenhum dado do arquivo

    while (fscanf(fp, "%d,%80[^,],%d,%d,%d,%d\n", &posisao, nome, &ouro, &prata, &bronze, &total)== 6 )
    {
        printf("Posisao: %d  Nome: %s Ouro: %d Prata: %d Bronze: %d Total: %d\n",posisao, nome, ouro, prata, bronze, total);
    }

    // Fecha arquivo
    fclose(fp);
}
