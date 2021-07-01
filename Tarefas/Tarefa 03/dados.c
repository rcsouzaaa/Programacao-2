/*                          Tarefa 03
 *
 *    Este programa le os dados do winterGames.csv de forma modularizada,
 *    aloca a memoria necessaria para armazena dentro de uma struct em dados.c
 *    e apresenta os dados organizados na tela na maim.c.
 *
 */

// Includes de sistema
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Includes do módulo
#include "dados.h"


// Estrutura de dados para armazenamento das variaveis
struct jogosIverno{
        int pos;
        char nome[64];
        int ouro;
        int prata;
        int bronze;
        int total_med;
};

dado_t *cria_dado (int pos, char *nome, int ouro, int prata, int bronze, int total_med){

    dado_t *dado = malloc(sizeof(dado_t));

    if (dado == NULL){
		perror("função: cria_casa");
		exit(EXIT_FAILURE);
	}

    dado->pos = pos;
    strncpy(dado->nome,nome,64);
    dado->ouro = ouro;
	dado->prata = prata;
	dado->bronze = bronze;
	dado->total_med = total_med;

	return dado;
}


// Ponteiro para alocação dinâmica dos dados
dado_t **ler_arquivo(char *nome_arquivo, int *tamanho){

	char linha[128];
	int contador = 0;

	int i = 0;

    int pos;
    char nome[64];
    int ouro;
    int prata;
    int bronze;
    int total_med;

    dado_t **dados;

    FILE *fp;
	fp = fopen("winterGames.csv","r");

	if (fp == NULL){
		perror("função: ler_arquivo_csv");
		exit(EXIT_FAILURE);
	}

	/* Conta as linhas */
	while (fgets(linha,128,fp) != NULL)
		contador++;

    rewind(fp);
	/* Ignora primeira linha */
	fgets(linha,128,fp);
	contador--;


// Manipulação de dados
	dados = malloc(sizeof(dado_t*) *contador);

	if (dados == NULL){
		perror("função: ler_arquivo_csv");
		exit(EXIT_FAILURE);
	}

// Escaneia cada dado e encrementa i para cada dado
	while(fscanf(fp, "%d,%63[^,],%d,%d,%d,%d\n",&pos, nome,&ouro,&prata,&bronze,&total_med) == 6){

        dados[i] = cria_dado(pos,nome,ouro,prata,bronze,total_med);
        i++;
    }

	fclose(fp);

	*tamanho = contador;
	return dados;
}

//libera dados
void libera_dados(dado_t **dados,int tamanho){
	int i;
	for (i=0; i<tamanho;i++){
        free(dados[i]);
    }
    free(dados);
}

//imprimindo dados
void imprime_dados(dado_t **dados, int tamanho){
	int i;
	printf(" pos | 			nome   		    |ouro |prata|bronz|tot\n");
	for(i = 0; i < tamanho;  i++){
  		printf(" %d | %s | %d| %d| %d| %d\n ", dados[i]->pos, dados[i]->nome, dados[i]->ouro, dados[i]->prata, dados[i]->bronze, dados[i]->total_med);
	}
}
