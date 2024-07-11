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

    strcpy(novo->cliente.cpf,cpf);

    printf("INFORME O TELEFONE DO CLIENTE: ");
    scanf(" %[^\n]",novo->cliente.telefone);

    printf("INFORME O ENDERECO DO CLIENTE: ");
    scanf(" %[^\n]",novo->cliente.endereco);

    printf("INFORME O EMAIL DO CLIENTE: ");
    scanf(" %[^\n]",novo->cliente.email);

    printf("INFORME O SEXO DO CLIENTE: ");
    scanf(" %[^\n]",novo->cliente.sexo);

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

    strcpy(novo->cliente.cnpj,cnpj);

    printf("INFORME O TELEFONE DA ORGANIZACAO: ");
    scanf(" %[^\n]",novo->cliente.telefone);

    printf("INFORME O ENDERECO DA ORGANIZACAO: ");
    scanf(" %[^\n]",novo->cliente.endereco);

    printf("INFORME O EMAIL DA ORGANIZACAO: ");
    scanf(" %[^\n]",novo->cliente.email);

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
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║             NOME             ║       CPF       ║    TELEFONE     ║          ENDEREÇO            ║             EMAIL            ║      SEXO      ║     STATUS    ║  ENTREGAS  ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

    while (aux)
    {
        printf("║ %-28s ║ %-15s ║ %-15s ║ %-28s ║ %-28s ║ %-14s ║ %-13s ║ %-10d ║\n",
        aux->cliente.nome,
        aux->cliente.cpf,
        aux->cliente.telefone,
        aux->cliente.endereco,
        aux->cliente.email,
        aux->cliente.sexo,
        aux->cliente.status_cliente,
        aux->cliente.conta_entregas);
        aux = aux->prox;
    }

    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

}

void listar_clientes_org(No_simples_clientes_organizacoes *lista){
    No_simples_clientes_organizacoes *aux;
    aux = lista;

    printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║             NOME             ║      CNPJ       ║    TELEFONE     ║          ENDEREÇO            ║             EMAIL            ║     STATUS    ║  ENTREGAS  ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

    while (aux)
    {
        printf("║ %-28s ║ %-15s ║ %-15s ║ %-28s ║ %-28s ║ %-13s ║ %-10d ║\n",
        aux->cliente.nome,
        aux->cliente.cnpj,
        aux->cliente.telefone,
        aux->cliente.endereco,
        aux->cliente.email,
        aux->cliente.status_organizacao,
        aux->cliente.conta_entregas);
        aux = aux->prox;
    }

    printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    
}

void menu_principal()
{
    printf("╔══════════════════════════════════════╗\n");
    printf("║         MENU TRANSPORTADORA          ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ [1] MENU DO CLIENTE PESSOA           ║\n");
    printf("║ [2] MENU DO CLIENTE ORGANIZAÇÃO      ║\n");
    printf("║ [3] SOBRE                            ║\n");
    printf("║ [0] SAIR                             ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}

void menu_organizacao(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║           MENU ORGANIZAÇÃO           ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ [1] ADICINOAR CLIENTE ORGANIZACAO    ║\n");
    printf("║ [2] REMOVER CLIENTE ORGANIZACAO      ║\n");
    printf("║ [3] EDITAR CLIENTE ORGANIZACAO       ║\n");
    printf("║ [4] LISTAR CLIENTES ORGANIZACAO      ║\n");
    printf("║ [5] CONSULTAR CLIENTE ORGANIZACAO    ║\n");
    printf("║ [6] HISTORICO DE PEDIDOS ORGANIZAÇÃO ║\n");
    printf("║ [7] REALIZAR POSTAGEM ORGANIZACAO    ║\n");
    printf("║ [0] SAIR                             ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}

void menu_cliente_pessoa(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║             MENU CLIENTE             ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ [1] ADICINOAR CLIENTE PESSOA         ║\n");
    printf("║ [2] REMOVER CLIENTE PESSOA           ║\n");
    printf("║ [3] EDITAR CLIENTE PESSOA            ║\n");
    printf("║ [4] LISTAR CLIENTES PESSOA           ║\n");
    printf("║ [5] CONSULTAR CLIENTE PESSOA         ║\n");
    printf("║ [6] HISTORICO DE PEDIDOS CLIENTE     ║\n");
    printf("║ [7] REALIZAR POSTAGEM POR PESSOA     ║\n");
    printf("║ [0] SAIR                             ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}


void menu_editar_cliente(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║         MENU EDITAR CLIENTE          ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ [1] EDITAR NOME                      ║\n");
    printf("║ [2] EDITAR CPF                       ║\n");
    printf("║ [3] EDITAR TELEFONE                  ║\n");
    printf("║ [4] EDITAR ENDEREÇO                  ║\n");
    printf("║ [5] EDITAR EMAIL                     ║\n");
    printf("║ [6] EDITAR SEXO                      ║\n");
    printf("║ [0] SAIR                             ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}

void editar_cliente_avulso(No_simples_clientes_pessoas *lista){
    if (lista == NULL){
        printf("Não existem clientes cadastrados!\n");
        return;
    }

    No_simples_clientes_pessoas *aux = lista;
    char cpf[15];

    printf("Informe o cpf do cliente que deseja editar: ");
    scanf(" %[^\n]", cpf);

    while (aux != NULL && strcmp(aux->cliente.cpf, cpf) != 0){
        aux = aux->prox;
    }

    if (aux == NULL){
        printf("Cliente não encontrado!\n");
        return;
    }

    int op;

    do
    {
        menu_editar_cliente();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Informe o novo nome do cliente: ");
            scanf(" %[^\n]", aux->cliente.nome);
            break;

        case 2:
            printf("Informe o novo cpf do cliente: ");
            scanf(" %[^\n]", aux->cliente.cpf);
            break;

        case 3:
            printf("Informe o novo telefone do cliente: ");
            scanf(" %[^\n]", aux->cliente.telefone);
            break;

        case 4:
            printf("Informe o novo endereço do cliente: ");
            scanf(" %[^\n]", aux->cliente.endereco);
            break;

        case 5:
            printf("Informe o novo email do cliente: ");
            scanf(" %[^\n]", aux->cliente.email);
            break;

        case 6:
            printf("Informe o novo sexo do cliente: ");
            scanf(" %[^\n]", aux->cliente.sexo);
            break;

        case 0:
            break;
        
        default:
            printf("Opção inválida!\n");
            break;
        }
    
        if (op != 0){
            printf("Deseja alterar mais alguma coisa (1 - SIM / 0 - NÃO): ");
            scanf("%d", &op);
        }
        
    } while (op != 0);
}