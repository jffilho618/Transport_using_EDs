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
    printf("║ [1] ADICIONAR CLIENTE ORGANIZACAO    ║\n");
    printf("║ [2] MUDAR STATUS CLIENTE ORGANIZACAO ║\n");
    printf("║ [3] EDITAR CLIENTE ORGANIZACAO       ║\n");
    printf("║ [4] LISTAR CLIENTES ORGANIZACAO      ║\n");
    printf("║ [5] CONSULTAR CLIENTE ORGANIZACAO    ║\n");
    printf("║ [6] HISTORICO DE PEDIDOS ORGANIZAÇÃO ║\n");
    printf("║ [7] REALIZAR POSTAGEM ORGANIZACAO    ║\n");
    printf("║ [0] MENU ANTERIOR                    ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}

void menu_cliente_pessoa(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║             MENU CLIENTE             ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ [1] ADICIONAR CLIENTE PESSOA         ║\n");
    printf("║ [2] MUDAR STATUS CLIENTE PESSOA      ║\n");
    printf("║ [3] EDITAR CLIENTE PESSOA            ║\n");
    printf("║ [4] LISTAR CLIENTES PESSOA           ║\n");
    printf("║ [5] CONSULTAR CLIENTE PESSOA         ║\n");
    printf("║ [6] HISTORICO DE PEDIDOS CLIENTE     ║\n");
    printf("║ [7] REALIZAR POSTAGEM POR PESSOA     ║\n");
    printf("║ [0] MENU ANTERIOR                    ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}

void menu_consulta_cliente(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║ [1] CONSULTAR PELO CPF               ║\n");
    printf("║ [2] CONSULTAR PELO NOME              ║\n");
    printf("║ [3] CONSULTAR PELO STATUS            ║\n");
    printf("║ [0] MENU ANTERIOR                    ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}

void menu_consulta_cliente_status(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║ [1] STATUS ATIVO                     ║\n");
    printf("║ [2] STATUS INATIVO                   ║\n");
    printf("║ [0] MENU ANTERIOR                    ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}

void menu_consulta_organizacao(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║ [1] CONSULTAR PELO CPF               ║\n");
    printf("║ [2] CONSULTAR PELO NOME              ║\n");
    printf("║ [3] CONSULTAR PELO STATUS            ║\n");
    printf("║ [0] MENU ANTERIOR                    ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}

void menu_consulta_organizacao_status(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║ [1] STATUS ATIVO                     ║\n");
    printf("║ [2] STATUS INATIVO                   ║\n");
    printf("║ [0] MENU ANTERIOR                    ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}

void menu_editar_status_cliente_avulso(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║ [1] BUSCAR PELO CPF                  ║\n");
    printf("║ [2] CONSULTAR PELO NOME              ║\n");
    printf("║ [0] MENU ANTERIOR                    ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
} 

void menu_editar_status_cliente_Organizacao(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║ [1] BUSCAR PELO CNPJ                 ║\n");
    printf("║ [2] CONSULTAR PELO NOME              ║\n");
    printf("║ [0] MENU ANTERIOR                    ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}  

void editar_status_cliente_avulso(No_simples_clientes_pessoas *lista, int opcao){
    if (lista == NULL){
        printf("Não existem clientes cadastrados!\n");
        return;
    }

    No_simples_clientes_pessoas *aux = lista;
    char cpf[15];
    char nome[50]; 
    
    if (opcao == 1){ 
        printf("Informe o cpf do cliente que deseja editar: ");
        scanf(" %[^\n]", cpf);

        while (aux != NULL && strcmp(aux->cliente.cpf, cpf) != 0){
            aux = aux->prox;
        }

        if (aux == NULL){
            printf("Cliente não encontrado!\n");
            return;
        } 
    }
    if(opcao == 2){ 
        printf("Informe o nome do cliente que deseja editar: ");
        scanf(" %[^\n]", nome);

        while (aux != NULL && strcmp(aux->cliente.nome, nome) != 0){
            aux = aux->prox;
        }

        if (aux == NULL){
            printf("Cliente não encontrado!\n");
            return;
        } 

    }    

    int op1, op2; 

    char status_temp[8]; 
    char status_ativo[8]; 

    strcpy(status_temp, "INATIVO"); 
    strcpy(status_ativo, "ATIVO"); 


    if(strcmp(aux->cliente.status_cliente, status_temp) == 0){
        do {
            printf("Organização encontrada, de nome %s, com o status atual %s, deseja torna-lo ATIVO ? (1-Para SIM, 2-Para NÃO)\n", aux->cliente.nome, aux->cliente.status_cliente); 
            scanf("%d", &op1); 
            if (op1 == 1) {
                strcpy(aux->cliente.status_cliente, status_ativo);  
                printf("STATUS ALTERADO COM SUCESSO!\n"); 
            } 
        } while (op1 < 1 || op1 > 2); 
    }else{
        do{
        printf("Cliente encontrado, de nome %s, com o status atual %s, deseja torna-lo INATIVO ? (1-Para SIM, 2-Para NÃO)\n", aux->cliente.nome, aux->cliente.status_cliente); 
        scanf("%d", &op2); 
            if(op2 == 1){
                strcpy(aux->cliente.status_cliente, status_temp);  
                printf("STATUS ALTERADO COM SUCESSO!\n"); 
            } 
        }while(op2 < 1 || op2 > 2);     
    
    } 

}     


void editar_status_cliente_organizacao(No_simples_clientes_organizacoes *lista, int opcao){
    if (lista == NULL){
        printf("Não existem clientes cadastrados!\n");
        return;
    }

    No_simples_clientes_organizacoes *aux = lista;
    char cnpj[15];
    char nome[50]; 
    
    if (opcao == 1){ 
        printf("Informe o CNPJ da Organização que deseja editar: ");
        scanf(" %[^\n]", cnpj);

        while (aux != NULL && strcmp(aux->cliente.cnpj, cnpj) != 0){
            aux = aux->prox;
        }

        if (aux == NULL){
            printf("Organização não encontrada!\n");
            return;
        } 
    }
    if (opcao == 2){ 
        printf("Informe o nome Fantasia da Organização que deseja editar: ");
        scanf(" %[^\n]", nome);

        while (aux != NULL && strcmp(aux->cliente.nome, nome) != 0){
            aux = aux->prox;
        }

        if (aux == NULL){
            printf("Organização não encontrada!\n");
            return;
        } 
    }    

    int op1, op2; 

    char status_temp[8];
    char status_ativo[8];

    strcpy(status_temp, "INATIVO"); 
    strcpy(status_ativo, "ATIVO"); 

    if (strcmp(aux->cliente.status_organizacao, status_temp) == 0) { 
        do {
            printf("Organização encontrada, de nome %s, com o status atual %s, deseja torna-lo ATIVO ? (1-Para SIM, 2-Para NÃO)\n", aux->cliente.nome, aux->cliente.status_organizacao); 
            scanf("%d", &op1); 
            if (op1 == 1) {
                strcpy(aux->cliente.status_organizacao, status_ativo);  
                printf("STATUS ALTERADO COM SUCESSO!\n"); 
            } 
        } while (op1 < 1 || op1 > 2); 
    } else {
        do {
            printf("Organização encontrada, de nome %s, com o status atual %s, deseja torna-lo INATIVO ? (1-Para SIM, 2-Para NÃO)\n", aux->cliente.nome, aux->cliente.status_organizacao); 
            scanf("%d", &op2); 
            if (op2 == 1) {
                strcpy(aux->cliente.status_organizacao, status_temp);  
                printf("STATUS ALTERADO COM SUCESSO!\n"); 
            } 
        } while (op2 < 1 || op2 > 2); 
    }
}


















void consulta_cliente_cpf(No_simples_clientes_pessoas *lista){
    if (lista==NULL)
    {
        printf("NÃO HA CLIENTES CADASTRADOS !!\n\n");
        return;
    }

    char cpf[15];
    printf("INFORME O CPF DO CLIENTE: ");
    scanf(" %[^\n]",cpf);

    No_simples_clientes_pessoas *aux;
    aux = lista;
    int cont=0;

    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║             NOME             ║       CPF       ║    TELEFONE     ║          ENDEREÇO            ║             EMAIL            ║      SEXO      ║     STATUS    ║  ENTREGAS  ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");


    while (aux)
    {
        if (strcmp(aux->cliente.cpf,cpf)==0)
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
            cont++;
        }
        aux = aux->prox;
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    if (cont==0)
    {
        printf("CLIENTE NÃO ENCONTRADO !!\n\n");
    }

}

void consulta_cliente_nome(No_simples_clientes_pessoas *lista){
    if (lista==NULL)
    {
        printf("NÃO HA CLIENTES CADASTRADOS !!\n\n");
        return;
    }

    char nome[50];
    printf("INFORME O NOME DO CLIENTE: ");
    scanf(" %[^\n]",nome);

    No_simples_clientes_pessoas *aux;
    aux = lista;
    int cont=0;

    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║             NOME             ║       CPF       ║    TELEFONE     ║          ENDEREÇO            ║             EMAIL            ║      SEXO      ║     STATUS    ║  ENTREGAS  ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

    while (aux)
    {
        if (strcmp(aux->cliente.nome,nome)==0)
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
            cont++;
        }
        aux = aux->prox;
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    if (cont==0)
    {
        printf("CLIENTE NÃO ENCONTRADO !!\n\n");
    }
}

void consulta_cliente_status_ativo(No_simples_clientes_pessoas *lista){
    if (lista==NULL)
    {
        printf("NÃO HA CLIENTES CADASTRADOS !!\n\n");
        return;
    }

    No_simples_clientes_pessoas *aux;
    aux = lista;
    int cont=0;

    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║             NOME             ║       CPF       ║    TELEFONE     ║          ENDEREÇO            ║             EMAIL            ║      SEXO      ║     STATUS    ║  ENTREGAS  ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

    while (aux)
    {
        if (strcmp(aux->cliente.status_cliente,"ATIVO")==0)
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
            cont++;
        }
        aux = aux->prox;
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    if (cont==0)
    {
        printf("CLIENTE NÃO ENCONTRADO !!\n\n");
    }
}

void consulta_cliente_status_inativo(No_simples_clientes_pessoas *lista){
    if (lista==NULL)
    {
        printf("NÃO HA CLIENTES CADASTRADOS !!\n\n");
        return;
    }

    No_simples_clientes_pessoas *aux;
    aux = lista;
    int cont=0;

    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║             NOME             ║       CPF       ║    TELEFONE     ║          ENDEREÇO            ║             EMAIL            ║      SEXO      ║     STATUS    ║  ENTREGAS  ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

    while (aux)
    {
        if (strcmp(aux->cliente.status_cliente,"INATIVO")==0)
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
            cont++;
        }
        aux = aux->prox;
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    if (cont==0)
    {
        printf("CLIENTE NÃO ENCONTRADO !!\n\n");
    }
}

void consulta_org_cnpj(No_simples_clientes_organizacoes *lista){
    if (lista==NULL)
    {
        printf("NÃO HA ORGANIZACOES CADASTRADAS !!\n\n");
        return;
    }

    char cnpj[20];
    printf("INFORME O CNPJ DA ORGANIZACAO: ");
    scanf(" %[^\n]",cnpj);

    No_simples_clientes_organizacoes *aux;
    aux = lista;
    int cont=0;

    printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║             NOME             ║      CNPJ       ║    TELEFONE     ║          ENDEREÇO            ║             EMAIL            ║     STATUS    ║  ENTREGAS  ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");


    while (aux)
    {
        if (strcmp(aux->cliente.cnpj,cnpj)==0)
        {
            printf("║ %-28s ║ %-15s ║ %-15s ║ %-28s ║ %-28s ║ %-13s ║ %-10d ║\n",
            aux->cliente.nome,
            aux->cliente.cnpj,
            aux->cliente.telefone,
            aux->cliente.endereco,
            aux->cliente.email,
            aux->cliente.status_organizacao,
            aux->cliente.conta_entregas);
            cont++;
        }
        aux = aux->prox;
    }

    printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    if (cont==0)
    {
        printf("ORGANIZACAO NÃO ENCONTRADA !!\n\n");
    }

}

void consulta_nome_org(No_simples_clientes_organizacoes *lista){
    if (lista==NULL)
    {
        printf("NÃO HA ORGANIZACOES CADASTRADAS !!\n\n");
        return;
    }

    char nome[50];
    printf("INFORME O NOME DA ORGANIZACAO: ");
    scanf(" %[^\n]",nome);

    No_simples_clientes_organizacoes *aux;
    aux = lista;
    int cont=0;

    printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║             NOME             ║      CNPJ       ║    TELEFONE     ║          ENDEREÇO            ║             EMAIL            ║     STATUS    ║  ENTREGAS  ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

    while (aux)
    {
        if (strcmp(aux->cliente.nome,nome)==0)
        {
            printf("║ %-28s ║ %-15s ║ %-15s ║ %-28s ║ %-28s ║ %-13s ║ %-10d ║\n",
            aux->cliente.nome,
            aux->cliente.cnpj,
            aux->cliente.telefone,
            aux->cliente.endereco,
            aux->cliente.email,
            aux->cliente.status_organizacao,
            aux->cliente.conta_entregas);
            cont++;
        }
        aux = aux->prox;
    }
    printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    
    if (cont==0)
    {
        printf("ORGANIZACAO NÃO ENCONTRADA !!\n\n");
    }

}

void consulta_org_status_ativo(No_simples_clientes_organizacoes *lista){
    if (lista==NULL)
    {
        printf("NÃO HA ORGANIZACOES CADASTRADAS !!\n\n");
        return;
    }

    No_simples_clientes_organizacoes *aux;
    aux = lista;
    int cont=0;

    printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║             NOME             ║      CNPJ       ║    TELEFONE     ║          ENDEREÇO            ║             EMAIL            ║     STATUS    ║  ENTREGAS  ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

    while (aux)
    {
        if (strcmp(aux->cliente.status_organizacao,"ATIVO")==0)
        {
            printf("║ %-28s ║ %-15s ║ %-15s ║ %-28s ║ %-28s ║ %-13s ║ %-10d ║\n",
            aux->cliente.nome,
            aux->cliente.cnpj,
            aux->cliente.telefone,
            aux->cliente.endereco,
            aux->cliente.email,
            aux->cliente.status_organizacao,
            aux->cliente.conta_entregas);
            cont++;
        }
        aux = aux->prox;
    }

    printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    if (cont==0)
    {
        printf("ORGANIZACAO NÃO ENCONTRADA !!\n\n");
    }
}

void consulta_org_status_inativo(No_simples_clientes_organizacoes *lista){
    if (lista==NULL)
    {
        printf("NÃO HA ORGANIZACOES CADASTRADAS !!\n\n");
        return;
    }

    No_simples_clientes_organizacoes *aux;
    aux = lista;
    int cont=0;

    printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║             NOME             ║      CNPJ       ║    TELEFONE     ║          ENDEREÇO            ║             EMAIL            ║     STATUS    ║  ENTREGAS  ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

    while (aux)
    {
        if (strcmp(aux->cliente.status_organizacao,"INATIVO")==0)
        {
            printf("║ %-28s ║ %-15s ║ %-15s ║ %-28s ║ %-28s ║ %-13s ║ %-10d ║\n",
            aux->cliente.nome,
            aux->cliente.cnpj,
            aux->cliente.telefone,
            aux->cliente.endereco,
            aux->cliente.email,
            aux->cliente.status_organizacao,
            aux->cliente.conta_entregas);
            cont++;
        }
        aux = aux->prox;
    }

    printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    if (cont==0)
    {
        printf("ORGANIZACAO NÃO ENCONTRADA !!\n\n");
    }
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



void menu_editar_organizacao(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║         MENU EDITAR ORGANIZAÇÃO      ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ [1] EDITAR NOME                      ║\n");
    printf("║ [2] EDITAR CNPJ                      ║\n");
    printf("║ [3] EDITAR TELEFONE                  ║\n");
    printf("║ [4] EDITAR ENDEREÇO                  ║\n");
    printf("║ [5] EDITAR EMAIL                     ║\n");
    printf("║ [0] SAIR                             ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}


void editar_cliente_organizacao(No_simples_clientes_organizacoes *lista){
    if (lista == NULL){
        printf("Não existem clientes cadastrados!\n");
        return;
    }

    No_simples_clientes_organizacoes *aux = lista;
    char cnpj[15];

    printf("Informe o cpf do cliente que deseja editar: ");
    scanf(" %[^\n]", cnpj);

    while (aux != NULL && strcmp(aux->cliente.cnpj, cnpj) != 0){
        aux = aux->prox;
    }

    if (aux == NULL){
        printf("Cliente não encontrado!\n");
        return;
    }

    int op;

    do
    {
        menu_editar_organizacao();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Informe o novo nome do cliente: ");
            scanf(" %[^\n]", aux->cliente.nome);
            break;

        case 2:
            printf("Informe o novo cpf do cliente: ");
            scanf(" %[^\n]", aux->cliente.cnpj);
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
