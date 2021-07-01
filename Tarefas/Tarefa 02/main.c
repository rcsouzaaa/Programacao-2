/*             Tarefa 02
 *
 *    Este programa le os dados do winterGames.csv,
 *    aloca a memoria necessaria para armazena dentro de uma struct
 *    e apresenta os dados organizados na tela.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados para armazenamento das variaveis
struct dados{
	int posisao;
	char nome[64];
	int ouro;
	int prata;
	int bronze;
	int total;
} ;

int main(){
    int i = 0;
    int n_linhas = 0;
    char info[64];

    // Ponteiro para alocação dinâmica dos dados
    struct dados *dados = NULL;

    FILE *fp = fopen("winterGames.csv","r");

    if (!fp){
        perror("main");
        exit(-1);
    }

    // Ignora primeira linha
    fgets(info,64, fp);

    // Manipulação de dados
    int buffer_pos, buffer_ouro, buffer_prata, buffer_bronze, buffer_total; //criando buffers para cada variavel
    char buffer_nome [64];
    dados = malloc(sizeof(struct dados) * n_linhas); //alocando memoria apos adquirir os dados

        if (dados == NULL){
    	perror("main");
    	exit(EXIT_FAILURE);
    }

    // Escaneia cada dado e encrementa i para cada dado
    while(fscanf(fp, "%d,%64[^,],%d,%d,%d,%d\n", &buffer_pos, buffer_nome, &buffer_ouro, &buffer_prata, &buffer_bronze, &buffer_total) == 6)
	{
		dados[i].posisao = buffer_pos;
		strncpy(paises[i].nome, buffer_nome, 64);
		dados[i].ouro = buffer_ouro;
		dados[i].prata = buffer_prata;
		dados[i].bronze = buffer_bronze;
		dados[i].total = buffer_total;
		i++;
	}

   //imprimindo dados
	for(i = 0; i < 29;  i++)
	{
		printf(" %3d | %36s| %3d| %3d| %3d| %3d\n ", paises[i].posisao, paises[i].nome,	paises[i].ouro,	paises[i].prata, paises[i].bronze, paises[i].total);
	}

    // Fecha arquivo
    fclose(fp);
    // libera memoria
    free(dados);
    return 0;
}
