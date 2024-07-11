#include <stdio.h>
#include "transport.h"
#include <stdlib.h>
#include <string.h>


No_simples_clientes_pessoas *cria_lista_pessoa(){
    return NULL;
}
No_simples_clientes_organizacoes *cria_lista_organizacao(){
    return NULL;
}


No_simples_clientes_pessoas *add_no_fim_pessoa(No_simples_clientes_pessoas *l){
    char cpf[15];
    int cont=0;
    printf("INFORME O CPF DO CLIENTE: ");
    scanf(" %[^\n]",cpf);
    printf("\n");

    No_simples_clientes_pessoas *aux2;
    aux2 = l;
    while (aux2)
    {
        if (strcmp(aux2->cliente.cpf,cpf)==0)
        {
            cont++;
        }
        aux2=aux2->prox;
    }
    if (cont>0)
    {
        printf("CLIENTE JA CADASTRADO !!\n\n");
        return l;
    }

    No_simples_clientes_pessoas *aux,*novo = (No_simples_clientes_pessoas*) malloc(sizeof(No_simples_clientes_pessoas));
    novo->prox=NULL;

    printf("INFORME O NOME DO CLIENTE: ");
    scanf(" %[^\n]",novo->cliente.nome);
    printf("\n");

    strcpy(novo->cliente.cpf,cpf);

    printf("INFORME O TELEFONE DO CLIENTE: ");
    scanf(" %[^\n]",novo->cliente.telefone);
    printf("\n");

    printf("INFORME O ENDERECO DO CLIENTE: ");
    scanf(" %[^\n]",novo->cliente.endereco);
    printf("\n");

    printf("INFORME O EMAIL DO CLIENTE: ");
    scanf(" %[^\n]",novo->cliente.email);
    printf("\n");

    printf("INFORME O SEXO DO CLIENTE: ");
    scanf(" %[^\n]",novo->cliente.sexo);
    printf("\n");

    strcpy(novo->cliente.status_cliente,"ATIVO");
    novo->cliente.conta_entregas=0;

    printf("CLIENTE CADASTRADO !!\n\n");
    
    if (l==NULL)
    {
        l=novo;
    }
    
    else
    {
        aux = l;
        while (aux->prox)
        {
            aux=aux->prox;
        }
        aux->prox=novo;
    }
    
    return l;

}

No_simples_clientes_organizacoes *add_no_fim_org(No_simples_clientes_organizacoes *l){
    char cnpj[20];
    int cont=0;
    printf("INFORME O CNPJ DA ORGANIZACAO: ");
    scanf(" %[^\n]",cnpj);
    printf("\n");

    No_simples_clientes_organizacoes *aux2;
    aux2 = l;
    while (aux2)
    {
        if (strcmp(aux2->cliente.cnpj,cnpj)==0)
        {
            cont++;
        }
        aux2=aux2->prox;
    }

    if (cont>0)
    {
        printf("ORGANIZACAO JA CADASTRADA !!\n\n");
        return l;
    }
    
    No_simples_clientes_organizacoes *aux,*novo = (No_simples_clientes_organizacoes*) malloc(sizeof(No_simples_clientes_organizacoes));
    novo->prox=NULL;
    
    printf("INFORME O NOME DA ORGANIZACAO: ");
    scanf(" %[^\n]",novo->cliente.nome);
    printf("\n");

    strcpy(novo->cliente.cnpj,cnpj);

    printf("INFORME O TELEFONE DA ORGANIZACAO: ");
    scanf(" %[^\n]",novo->cliente.telefone);
    printf("\n");

    printf("INFORME O ENDERECO DA ORGANIZACAO: ");
    scanf(" %[^\n]",novo->cliente.endereco);
    printf("\n");

    printf("INFORME O EMAIL DA ORGANIZACAO: ");
    scanf(" %[^\n]",novo->cliente.email);
    printf("\n");

    strcpy(novo->cliente.status_organizacao,"ATIVO");
    novo->cliente.conta_entregas=0;

    printf("ORGANIZACAO CADASTRADA !!\n\n");

    if (l==NULL)
    {
        l=novo;
    }
    
    else
    {
        aux = l;
        while (aux->prox)
        {
            aux=aux->prox;
        }
        aux->prox=novo;
    }
    
    return l;

}


void listar_clientes_pessoa(No_simples_clientes_pessoas *lista){
    No_simples_clientes_pessoas *aux;
    aux = lista;
    while (aux)
    {
        printf("NOME: %s\n",aux->cliente.nome);
        printf("CPF: %s\n",aux->cliente.cpf);
        printf("TELEFONE: %s\n",aux->cliente.telefone);
        printf("ENDERECO: %s\n",aux->cliente.endereco);
        printf("EMAIL: %s\n",aux->cliente.email);
        printf("SEXO: %s\n",aux->cliente.sexo);
        printf("STATUS: %s\n",aux->cliente.status_cliente);
        printf("ENTREGAS: %d\n",aux->cliente.conta_entregas);
        printf("\n");
        aux=aux->prox;
    }
    
}

void listar_clientes_org(No_simples_clientes_organizacoes *lista){
    No_simples_clientes_organizacoes *aux;
    aux = lista;
    while (aux)
    {
        printf("NOME: %s\n",aux->cliente.nome);
        printf("CNPJ: %s\n",aux->cliente.cnpj);
        printf("TELEFONE: %s\n",aux->cliente.telefone);
        printf("ENDERECO: %s\n",aux->cliente.endereco);
        printf("EMAIL: %s\n",aux->cliente.email);
        printf("STATUS: %s\n",aux->cliente.status_organizacao);
        printf("ENTREGAS: %d\n",aux->cliente.conta_entregas);
        printf("\n");
        aux=aux->prox;
    }
    
}