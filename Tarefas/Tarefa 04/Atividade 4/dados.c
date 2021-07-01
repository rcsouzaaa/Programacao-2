#include <stdio.h>
#include <stdlib.h>


#include "dados.h"
#include "lista_enc.h"
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
    int tamanho = 0;
    dado_t *dados = malloc(sizeof(dado_t));
    if ( dados == NULL)
    {
        perror( "main : " );
        exit(1);
    }
    tamanho = strlen(nome);
    dados->nome = malloc(tamanho+1);
    if ( dados->nome == NULL)
    {
        perror( "main : " );
        exit(1);
    }
    strncpy(dados->nome,nome,tamanho+1);
    dados->pos=pos;
    dados->ouro=ouro;
    dados->prata=prata;
    dados->bronze=bronze;
    dados->total_med=total_med;
    return dados;
}



lista_t *ler_dados(char *nome_do_arquivo)
{

    char buffer_string[TAM_BUFFER];
    char buffer_nome [64];
    int pos=0, ouro=0, prata=0, bronze=0, total_med=0;
    int ret=6;


    //abrir o arquivo
    FILE *fp = fopen(nome_do_arquivo, "r");
    if (fp == NULL)
    {
        perror("Erro em main: fopen");
        exit(EXIT_FAILURE);
    }
    //criando a lista
    lista_t *lista_de_dados=cria_lista_enc();

    // pegar a linha
    while(fgets(buffer_string,128,fp)!=NULL)
    {
        ret=sscanf(buffer_string,"%d,%46[^,],%d,%d,%d,%d\n",&pos, buffer_nome,&ouro,&prata,&bronze,&total_med);


        dado_t *dados_temp=cria_dado(pos,buffer_nome,ouro,prata,bronze,total_med);
        no_t *endereco_no=cria_no(dados_temp);
        add_cauda(lista_de_dados,endereco_no);
    }



    fclose(fp);
    return (lista_de_dados);
}




void no_de_dados(lista_t *lista)
{
    no_t * no = obtem_cabeca(lista);

    while (no != NULL)
    {
        char *nome = obtem_dado(no);
        free(nome);
        no_t * prox=obtem_proximo(no);
        free(no);
        no=prox;
    }
}

void print_dados(lista_t *lista)
{
    no_t *elemento = obtem_cabeca(lista);
    dado_t* pais;
    int i;

    for (i=0; i<tamanho_lista(lista); i++)
    {
        pais = obtem_dado(elemento);
        printf("%d| %40s| %d| %d| %d| %d\n",pais->pos,pais->nome,  pais->bronze, pais->ouro, pais->prata, pais->total_med);
        elemento=obtem_proximo(elemento);
    }
}

void libera_dados(lista_t *lista)
{
    no_t *meu_no=obtem_cabeca(lista);
    while (meu_no!=NULL)
    {
        dado_t *pais=obtem_dado(meu_no);
        free(pais->nome);
        free(pais);
        no_t *proximo=obtem_proximo(meu_no);
        free(meu_no);
        meu_no=proximo;
    }
    free(lista);
}
