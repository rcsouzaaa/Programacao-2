#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "fila.h"
#include "no.h"


#define TAM_BUFFER 128

struct dados
{
    int pos;
    char *nome;
    int ouro;
    int prata;
    int bronze;
    int total_med;
};


dado_t *cria_dado(int pos,char *nome,int ouro,int prata,int bronze,int total_med)
{
    int tam = 0;
    dado_t *dados = malloc(sizeof(dado_t));
    if ( dados == NULL)
    {
        perror( "main : " );
        exit(1);
    }
    tam = strlen(nome);
    dados->nome = malloc(tam+1);
    if ( dados->nome == NULL)
    {
        perror( "main : " );
        exit(1);
    }
    strncpy(dados->nome,nome,tam+1);
    dados->pos=pos;
    dados->ouro=ouro;
    dados->prata=prata;
    dados->bronze=bronze;
    dados->total_med=total_med;
    return dados;
}


fila_t *ler_dados(char *nome_do_arquivo)
{

    char buffer_string[TAM_BUFFER];
    char buffer_nome [64];
    int pos=0, ouro=0, prata=0, bronze=0, total_med=0;
    //int ret=6;


    //abrir o arquivo
    FILE *fp = fopen(nome_do_arquivo, "r");
    if (fp == NULL)
    {
        perror("Erro em main: fopen");
        exit(EXIT_FAILURE);
    }
    //criando a lista
    fila_t *fila_de_dados=cria_fila();

    // pegar a linha
    while(fgets(buffer_string,128,fp)!=NULL)
    {
        sscanf(buffer_string,"%d,%46[^,],%d,%d,%d,%d\n",&pos, buffer_nome,&ouro,&prata,&bronze,&total_med);

        enqueue(cria_no(cria_dado(pos,buffer_nome,ouro,prata,bronze,total_med)),fila_de_dados);
    }


    fclose(fp);
    return (fila_de_dados);
}




void no_de_dados(fila_t *fila)
{
    no_t * no = obtem_fila(fila);

    while (no != NULL)
    {
        char *nome = obtem_dado(no);
        free(nome);
        no_t * prox=obtem_proximo(no);
        free(no);
        no=prox;
    }
}

void print_dados(fila_t *fila)//dequeue
{
    no_t *elemento = obtem_fila(fila);
    dado_t* dado_temp;
    int i;

    for (i=0; i<tamanho_fila(fila)-1; i++)
    {
        dado_temp = obtem_dado(elemento);
        printf("%d| %40s| %d| %d| %d| %d\n",dado_temp->pos,dado_temp->nome,  dado_temp->bronze, dado_temp->ouro, dado_temp->prata, dado_temp->total_med);
        elemento=obtem_proximo(elemento);
    }
}

void libera_dados(fila_t *fila)//
{
    no_t *meu_no=obtem_fila(fila);
    while (meu_no!=NULL)
    {
        //dado_t *dado_temp=obtem_dado(meu_no);
        no_t *proximo=obtem_proximo(meu_no);
        free(obtem_dado(meu_no));
        meu_no=proximo;
    }
    free(fila);
}
