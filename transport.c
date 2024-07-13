#include <stdio.h>
#include "transport.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <time.h>


char* obter_hora_atual() {
    time_t tempo_bruto;
    struct tm *info_tempo;
    static char hora_str[9]; // "HH:MM:SS" + terminador nulo

    // Obter a hora atual
    time(&tempo_bruto);
    // Converter para o formato de hora local
    info_tempo = localtime(&tempo_bruto);

    // Formatar a hora como "HH:MM:SS"
    strftime(hora_str, sizeof(hora_str), "%H:%M:%S", info_tempo);

    return hora_str;
}

char* obter_data_atual() {
    time_t tempo_bruto;
    struct tm *info_tempo;
    char *data_str = malloc(11 * sizeof(char)); // Alocar memória para "DD/MM/AAAA" + terminador nulo

    if (data_str == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(1);
    }

    // Obter a data atual
    time(&tempo_bruto);
    // Converter para o formato de data local
    info_tempo = localtime(&tempo_bruto);

    // Formatar a data como "DD/MM/AAAA"
    strftime(data_str, 11, "%d/%m/%Y", info_tempo);

    return data_str;
}

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
    printf("║ [3] MENU ENTREGAS                    ║\n");
    printf("║ [4] SOBRE                            ║\n");
    printf("║ [0] SAIR                             ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
}

void menu_entregas(){
    printf("╔══════════════════════════════════════╗\n");
    printf("║            MENU ENTREGAS             ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ [1] PEDIDOS ESPERANDO ENTREGA        ║\n");
    printf("║ [2] REALIZAR ENTREGA                 ║\n");
    printf("║ [3] HISTORICO DE ENVIADAS PESSOA     ║\n");
    printf("║ [4] HISTORICO DE RECEBIDOS PESSOA    ║\n");
    printf("║ [5] HISTORICO DE ENVIADAS ORG        ║\n");
    printf("║ [6] HISTORICO DE RECEBIDOS ORG       ║\n");
    printf("║ [7] PRODUTOS DEVOLVIDOS              ║\n");
    printf("║ [0] MENU ANTERIOR                    ║\n");
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



Fila* fila_cria(void){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int fila_vazia(Fila* f){
    if (f == NULL || f->inicio == NULL){
        return 1;
    }

    return 0;
}

void fila_insere_ordenado(Fila* f, Entrega *entrega) {
    No *novo = (No*)malloc(sizeof(No));
    novo->entrega = entrega;
    novo->prox = NULL;

    // Se a fila estiver vazia
    if (fila_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
        return;
    }

    No *atual = f->inicio;
    No *anterior = NULL;

    // Percorrer a fila para encontrar a posição correta
    while (atual != NULL && strcmp(atual->entrega->destinatario->cpf, entrega->destinatario->cpf) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se inserindo no início da fila
    if (anterior == NULL) {
        novo->prox = f->inicio;
        f->inicio = novo;
    } else {
        // Inserir no meio ou fim da fila
        anterior->prox = novo;
        novo->prox = atual;
    }

    // Ajustar o ponteiro do fim da fila, se necessário
    if (novo->prox == NULL){
        f->fim = novo;
    }
}


Entrega *fila_retira(Fila** f) {
    if (fila_vazia(*f)) {
        return NULL;
    }

    No *aux = (*f)->inicio;
    Entrega *entrega = aux->entrega;

    (*f)->inicio = aux->prox;

    if ((*f)->inicio == NULL) {
        (*f)->fim = NULL;
    }

    free(aux);

    return entrega;
}


No_simples_entregas *cria_lista_entregas(){
    return NULL;
}

void add_inicio_entrega(No_simples_entregas **lista, Entrega *entrega){
    No_simples_entregas *novo = (No_simples_entregas*)malloc(sizeof(No_simples_entregas));
    if (novo == NULL){
        printf("Memória insuficiente!\n");
        return;
    }

    if (*lista == NULL){
        novo->entrega = entrega;
        novo->prox = NULL;
        *lista = novo;
    } else {
        novo->entrega = entrega;
        novo->prox = *lista;
        *lista = novo;
    }
    
}


int sorteia_ids(int vet[], int *n){
    int num_aleatorio, cont = *n;
    bool num_repetido;

    srand(time(NULL));

    do
    {
        num_repetido = false;
        num_aleatorio = rand() % 99 + 1;
        for(int k = 0; k < cont; k++){
            if(vet[k] == num_aleatorio){
                num_repetido = true;
                break;
            }
        }
        if(!num_repetido){
            vet[*n] = num_aleatorio;
            (*n)++;
        }
    } while (num_repetido);

    return num_aleatorio;

}

Pilha_nao_entregues *criaPilha(){
    return NULL;
}

int pilhaVazia(Pilha_nao_entregues *pilha){
    if(pilha == NULL){
        return 1;
    }

    return 0;
}

Entrega *pop(Pilha_nao_entregues **pilha) {
    if (pilhaVazia(*pilha)) {
        printf("A pilha está vazia!\n");
        return NULL;
    }

    Pilha_nao_entregues *aux = *pilha;
    Entrega *entrega = aux->entrega;
    *pilha = aux->prox;
    free(aux);

    return entrega;
}

void push(Pilha_nao_entregues **pilha, Entrega *entrega){
    Pilha_nao_entregues *novo = (Pilha_nao_entregues*)malloc(sizeof(Pilha_nao_entregues));
    if (novo == NULL){
        printf("Memória insuficiente!\n");
        return;
    }

    novo->entrega = entrega;
    novo->prox = *pilha;
    *pilha = novo;
}

Fila *realizar_postagem_por_pessoa(Fila *fila, No_simples_clientes_pessoas *lista, int *conta_entregas, int vet[], int *n){
    if (lista == NULL){
        printf("Não existem clientes cadastrados!\n");
        return fila;
    }

    if (*conta_entregas == 6){
        printf("Limite de postagens atingido!\n");
        return fila;
    }
    

    No_simples_clientes_pessoas *aux_remetente = lista;
    char cpf[15];

    printf("INFORME O CPF DO CLIENTE QUE DESEJA REALIZAR A POSTAGEM: ");
    scanf(" %[^\n]", cpf);

    while (aux_remetente != NULL && strcmp(aux_remetente->cliente.cpf, cpf) != 0){
        aux_remetente = aux_remetente->prox;
    }

    if (aux_remetente == NULL){
        printf("CLIENTE NÃO ENCONTRADO !\n");
        return fila;
    }

    

    
    Entrega *entrega = (Entrega *)malloc(sizeof(Entrega));
    entrega->remetente_pessoa = (Cliente_pessoa*) malloc(sizeof(Cliente_pessoa));
    entrega->destinatario = (Cliente_pessoa*) malloc(sizeof(Cliente_pessoa));

    if (entrega == NULL){
        printf("Memória insuficiente!\n");
        return fila;
    }

    entrega->id =  sorteia_ids(vet, n);

    printf("INFORME O NOME DO DESTINATÁRIO: ");
    scanf(" %[^\n]", entrega->destinatario->nome);

    printf("INFORME O CPF DO DESTINATÁRIO: ");
    scanf(" %[^\n]", entrega->destinatario->cpf);

    printf("INFORME O TELEFONE DO DESTINATÁRIO: ");
    scanf(" %[^\n]", entrega->destinatario->telefone);

    printf("INFORME O ENDEREÇO DO DESTINATÁRIO: ");
    scanf(" %[^\n]", entrega->destinatario->endereco);

    printf("INFORME O EMAIL DO DESTINATÁRIO: ");
    scanf(" %[^\n]", entrega->destinatario->email);

    printf("INFORME O SEXO DO DESTINATÁRIO: ");
    scanf(" %[^\n]", entrega->destinatario->sexo);

    entrega->remetente_pessoa = &(aux_remetente->cliente);
    entrega->horaPostagem = obter_hora_atual();
    entrega->dataPostagem = obter_data_atual();

    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                       NOTA FISCAL                                                  ║\n");
    printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

    printf("║ %-25s : %-56d               ║\n", "ID DO PEDIDO", entrega->id);
    printf("║ %-25s : %-56s               ║\n", "NOME DO REMETENTE", aux_remetente->cliente.nome);
    printf("║ %-25s : %-56s               ║\n", "CPF DO REMETENTE", aux_remetente->cliente.cpf);
    printf("║ %-25s : %-56s               ║\n", "TELEFONE DO REMETENTE", aux_remetente->cliente.telefone);
    printf("║ %-26s : %-56s               ║\n", "ENDEREÇO DO REMETENTE", aux_remetente->cliente.endereco);
    printf("║ %-25s : %-56s               ║\n", "EMAIL DO REMETENTE", aux_remetente->cliente.email);
    printf("║ %-25s : %-56s               ║\n", "SEXO DO REMETENTE", aux_remetente->cliente.sexo);
    printf("║ %-25s : %-56s               ║\n", "HORA DA POSTAGEM", entrega->horaPostagem);
    printf("║ %-25s : %-56s               ║\n", "DATA DA POSTAGEM", entrega->dataPostagem);

    printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

    printf("║ %-26s : %-56s               ║\n", "NOME DO DESTINATÁRIO", entrega->destinatario->nome);
    printf("║ %-26s : %-56s               ║\n", "CPF DO DESTINATÁRIO", entrega->destinatario->cpf);
    printf("║ %-26s : %-56s               ║\n", "TELEFONE DO DESTINATÁRIO", entrega->destinatario->telefone);
    printf("║ %-27s : %-56s               ║\n", "ENDEREÇO DO DESTINATÁRIO", entrega->destinatario->endereco);
    printf("║ %-26s : %-56s               ║\n", "EMAIL DO DESTINATÁRIO", entrega->destinatario->email);
    printf("║ %-26s : %-56s               ║\n", "SEXO DO DESTINATÁRIO", entrega->destinatario->sexo);

    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");



    int opcao;

    printf("VOCE DESEJA REALIZAR A POSTAGEM ? (1-SIM, 2-NÃO): ");
    scanf("%d", &opcao);

    if(opcao == 2){
        printf("POSTAGEM CANCELADA!\n");
        free(entrega);
        return fila;
    }

    fila_insere_ordenado(fila, entrega);
    (*conta_entregas)++;
    strcpy(entrega->status, "PENDENTE");


    printf("POSTAGEM REALIZADA COM SUCESSO!\n");

    return fila;
}

void realizar_entrega(Fila *fila, int *conta_entregas, No_simples_entregas **historico_entregas, Pilha_nao_entregues **pilha_nao_entregues, No_simples_entregas **lista_devolucao) {
    if (fila_vazia(fila)) {
        printf("NÃO EXISTEM ENTREGAS PENDENTES!\n");
        return;
    }

    if (*conta_entregas < 6) {
        printf("LIMITE DE POSTAGENS NÃO ATINGIDO!\n");
        return;
    }

    int valor;
    srand(time(NULL)); // Inicializa o gerador de números aleatórios apenas uma vez

    while (!fila_vazia(fila)) {
        No *atual = fila->inicio; // Sempre pega o início da fila
        valor = rand() % 5 + 1;
        printf("VALOR: %d\n", valor);

        // Processar a entrega atual
        if (valor == 1 || valor == 3 || valor == 5) {
            strcpy(atual->entrega->status, "ENTREGUE");
            Entrega *entrega = fila_retira(&fila);
            entrega->remetente_pessoa->conta_entregas++;
            entrega->horaEntrega = obter_hora_atual();
            entrega->dataEntrega = obter_data_atual();
            entrega->score += 5;
            add_inicio_entrega(historico_entregas, entrega);
        } else {
            Entrega *entrega = fila_retira(&fila);
            push(pilha_nao_entregues, entrega);
        }

        // Atualizar atual para a próxima entrega e verificar destinatário
        while (fila->inicio != NULL && strcmp(fila->inicio->entrega->destinatario->cpf, atual->entrega->destinatario->cpf) == 0) {
            atual = fila->inicio;
            if (valor == 1 || valor == 3 || valor == 5) {
                strcpy(atual->entrega->status, "ENTREGUE");
                Entrega *entrega = fila_retira(&fila);
                entrega->remetente_pessoa->conta_entregas++;
                entrega->horaEntrega = obter_hora_atual();
                entrega->dataEntrega = obter_data_atual();
                entrega->score += 5;
                add_inicio_entrega(historico_entregas, entrega);
            } else {
                Entrega *entrega = fila_retira(&fila);
                push(pilha_nao_entregues, entrega);
            }
        }
    }

    while (!pilhaVazia(*pilha_nao_entregues)) {
        Pilha_nao_entregues *aux = *pilha_nao_entregues;
        int valor = rand() % 5 + 1;
        printf("VALOR: %d\n", valor);

        // Processar a entrega do topo da pilha
        if (valor == 1 || valor == 3 || valor == 5){
            Entrega *entrega = pop(pilha_nao_entregues);
            strcpy(entrega->status, "ENTREGUE");
            entrega->remetente_pessoa->conta_entregas++;
            entrega->horaEntrega = obter_hora_atual();
            entrega->dataEntrega = obter_data_atual();
            entrega->score += 3;
            add_inicio_entrega(historico_entregas, entrega);
        } else {
            Entrega *entrega = pop(pilha_nao_entregues);
            strcpy(entrega->status, "DEVOLVIDO");
            entrega->horaEntrega = obter_hora_atual();
            entrega->dataEntrega = obter_data_atual();
            if (entrega->score > 0) {
                entrega->score -= 1;
            }
            
            add_inicio_entrega(lista_devolucao, entrega);
        }

        // Processar entregas subsequentes com o mesmo destinatário usando o mesmo valor
        while (*pilha_nao_entregues != NULL && strcmp((*pilha_nao_entregues)->entrega->destinatario->cpf, aux->entrega->destinatario->cpf) == 0) {
            aux = *pilha_nao_entregues;

            if (valor == 1 || valor == 3 || valor == 5){
                Entrega *entrega = pop(pilha_nao_entregues);
                strcpy(entrega->status, "ENTREGUE");
                entrega->remetente_pessoa->conta_entregas++;
                entrega->horaEntrega = obter_hora_atual();
                entrega->dataEntrega = obter_data_atual();
                entrega->score += 3;
                add_inicio_entrega(historico_entregas, entrega);
            } else {
                Entrega *entrega = pop(pilha_nao_entregues);
                strcpy(entrega->status, "DEVOLVIDO");
                entrega->horaEntrega = obter_hora_atual();
                entrega->dataEntrega = obter_data_atual();
                if (entrega->score > 0) {
                    entrega->score -= 1;
                }
                add_inicio_entrega(lista_devolucao, entrega);
            }
        }
    
    }

    
    (*conta_entregas) = 0;
}


void imprimir_fila(Fila *fila) {
    No *atual = fila->inicio;

    printf("╔══════╦══════════════════╦════════════════════════════════════╦════════════╦══════════╦════════════╗\n");
    printf("║  ID  ║ CPF DESTINATÁRIO ║              ENDEREÇO              ║    DATA    ║   HORA   ║   STATUS   ║\n");
    printf("╠══════╬══════════════════╬════════════════════════════════════╬════════════╬══════════╬════════════╣\n");

    while (atual != NULL) {
        printf("║ %-4d ║ %-16s ║ %-34s ║ %-10s ║ %-8s ║ %-10s ║\n", 
                atual->entrega->id,
                atual->entrega->destinatario->cpf, 
                atual->entrega->destinatario->endereco, 
                atual->entrega->dataPostagem, 
                atual->entrega->horaPostagem,
                atual->entrega->status);
        atual = atual->prox;
    }

    printf("╚══════╩══════════════════╩════════════════════════════════════╩════════════╩══════════╩════════════╝\n");
}

void historico_recebidos_clientes(No_simples_entregas *lista){
    if (lista == NULL){
        printf("Não existem entregas realizadas!\n");
        return;
    }

    No_simples_entregas *aux = lista;
    char cpf[15];

    printf("INFORME O CPF DO CLIENTE QUE DESEJA CONSULTAR O HISTÓRICO DE ENTREGAS: ");
    scanf(" %[^\n]", cpf);

    while (aux !=NULL)
    {
        if (strcmp(aux->entrega->destinatario->cpf, cpf) == 0)
        {
            printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
            printf("║                                       NOTA FISCAL                                                  ║\n");
            printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

            

            printf("║ %-25s : %-56d               ║\n", "ID DO PEDIDO", aux->entrega->id);
            printf("║ %-25s : %-56s               ║\n", "NOME DO REMETENTE", aux->entrega->remetente_pessoa->nome);
            printf("║ %-25s : %-56s               ║\n", "CPF DO REMETENTE", aux->entrega->remetente_pessoa->cpf);
            printf("║ %-25s : %-56s               ║\n", "TELEFONE DO REMETENTE", aux->entrega->remetente_pessoa->telefone);
            printf("║ %-26s : %-56s               ║\n", "ENDEREÇO DO REMETENTE", aux->entrega->remetente_pessoa->endereco);
            printf("║ %-25s : %-56s               ║\n", "EMAIL DO REMETENTE", aux->entrega->remetente_pessoa->email);
            printf("║ %-25s : %-56s               ║\n", "SEXO DO REMETENTE", aux->entrega->remetente_pessoa->sexo);
            printf("║ %-25s : %-56s               ║\n", "HORA DA POSTAGEM", aux->entrega->horaPostagem);
            printf("║ %-25s : %-56s               ║\n", "DATA DA POSTAGEM", aux->entrega->dataPostagem);

            printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

            printf("║ %-26s : %-56s               ║\n", "NOME DO DESTINATÁRIO", aux->entrega->destinatario->nome);
            printf("║ %-26s : %-56s               ║\n", "CPF DO DESTINATÁRIO", aux->entrega->destinatario->cpf);
            printf("║ %-26s : %-56s               ║\n", "TELEFONE DO DESTINATÁRIO", aux->entrega->destinatario->telefone);
            printf("║ %-27s : %-56s               ║\n", "ENDEREÇO DO DESTINATÁRIO", aux->entrega->destinatario->endereco);
            printf("║ %-26s : %-56s               ║\n", "EMAIL DO DESTINATÁRIO", aux->entrega->destinatario->email);
            printf("║ %-26s : %-56s               ║\n", "SEXO DO DESTINATÁRIO", aux->entrega->destinatario->sexo);
            printf("║ %-25s : %-56s               ║\n", "HORA DA ENTREGA", aux->entrega->horaEntrega);
            printf("║ %-25s : %-56s               ║\n", "DATA DA ENTREGA", aux->entrega->dataEntrega);
            printf("║ %-25s : %-56s               ║\n", "STATUS", aux->entrega->status);

            printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        }
        aux = aux->prox;
    }
    

}

void historico_enviados_clientes(No_simples_entregas *lista){
    if (lista == NULL){
        printf("Não existem entregas realizadas!\n");
        return;
    }

    No_simples_entregas *aux = lista;
    char cpf[15];

    printf("INFORME O CPF DO CLIENTE QUE DESEJA CONSULTAR O HISTÓRICO DE ENTREGAS: ");
    scanf(" %[^\n]", cpf);

    while (aux !=NULL)
    {
        if (strcmp(aux->entrega->remetente_pessoa->cpf, cpf) == 0)
        {
            printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
            printf("║                                       NOTA FISCAL                                                  ║\n");
            printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

            

            printf("║ %-25s : %-56d               ║\n", "ID DO PEDIDO", aux->entrega->id);
            printf("║ %-25s : %-56s               ║\n", "NOME DO REMETENTE", aux->entrega->remetente_pessoa->nome);
            printf("║ %-25s : %-56s               ║\n", "CPF DO REMETENTE", aux->entrega->remetente_pessoa->cpf);
            printf("║ %-25s : %-56s               ║\n", "TELEFONE DO REMETENTE", aux->entrega->remetente_pessoa->telefone);
            printf("║ %-26s : %-56s               ║\n", "ENDEREÇO DO REMETENTE", aux->entrega->remetente_pessoa->endereco);
            printf("║ %-25s : %-56s               ║\n", "EMAIL DO REMETENTE", aux->entrega->remetente_pessoa->email);
            printf("║ %-25s : %-56s               ║\n", "SEXO DO REMETENTE", aux->entrega->remetente_pessoa->sexo);
            printf("║ %-25s : %-56s               ║\n", "HORA DA POSTAGEM", aux->entrega->horaPostagem);
            printf("║ %-25s : %-56s               ║\n", "DATA DA POSTAGEM", aux->entrega->dataPostagem);

            printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

            printf("║ %-26s : %-56s               ║\n", "NOME DO DESTINATÁRIO", aux->entrega->destinatario->nome);
            printf("║ %-26s : %-56s               ║\n", "CPF DO DESTINATÁRIO", aux->entrega->destinatario->cpf);
            printf("║ %-26s : %-56s               ║\n", "TELEFONE DO DESTINATÁRIO", aux->entrega->destinatario->telefone);
            printf("║ %-27s : %-56s               ║\n", "ENDEREÇO DO DESTINATÁRIO", aux->entrega->destinatario->endereco);
            printf("║ %-26s : %-56s               ║\n", "EMAIL DO DESTINATÁRIO", aux->entrega->destinatario->email);
            printf("║ %-26s : %-56s               ║\n", "SEXO DO DESTINATÁRIO", aux->entrega->destinatario->sexo);
            printf("║ %-25s : %-56s               ║\n", "HORA DA ENTREGA", aux->entrega->horaEntrega);
            printf("║ %-25s : %-56s               ║\n", "DATA DA ENTREGA", aux->entrega->dataEntrega);
            printf("║ %-25s : %-56s               ║\n", "STATUS", aux->entrega->status);

            printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        }
        aux = aux->prox;
    }
    

}

void historico_devolucao(No_simples_entregas *lista){
    if (lista == NULL){
        printf("NÃO EXISTEM ENTREGAS DEVOLVIDAS !\n");
        return;
    }

    No_simples_entregas *aux = lista;

    while (aux != NULL)
    {
        printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                                       NOTA FISCAL                                                  ║\n");
        printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

        

        printf("║ %-25s : %-56d               ║\n", "ID DO PEDIDO", aux->entrega->id);
        printf("║ %-25s : %-56s               ║\n", "NOME DO REMETENTE", aux->entrega->remetente_pessoa->nome);
        printf("║ %-25s : %-56s               ║\n", "CPF DO REMETENTE", aux->entrega->remetente_pessoa->cpf);
        printf("║ %-25s : %-56s               ║\n", "TELEFONE DO REMETENTE", aux->entrega->remetente_pessoa->telefone);
        printf("║ %-26s : %-56s               ║\n", "ENDEREÇO DO REMETENTE", aux->entrega->remetente_pessoa->endereco);
        printf("║ %-25s : %-56s               ║\n", "EMAIL DO REMETENTE", aux->entrega->remetente_pessoa->email);
        printf("║ %-25s : %-56s               ║\n", "SEXO DO REMETENTE", aux->entrega->remetente_pessoa->sexo);
        printf("║ %-25s : %-56s               ║\n", "HORA DA POSTAGEM", aux->entrega->horaPostagem);
        printf("║ %-25s : %-56s               ║\n", "DATA DA POSTAGEM", aux->entrega->dataPostagem);

        printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");

        printf("║ %-26s : %-56s               ║\n", "NOME DO DESTINATÁRIO", aux->entrega->destinatario->nome);
        printf("║ %-26s : %-56s               ║\n", "CPF DO DESTINATÁRIO", aux->entrega->destinatario->cpf);
        printf("║ %-26s : %-56s               ║\n", "TELEFONE DO DESTINATÁRIO", aux->entrega->destinatario->telefone);
        printf("║ %-27s : %-56s               ║\n", "ENDEREÇO DO DESTINATÁRIO", aux->entrega->destinatario->endereco);
        printf("║ %-26s : %-56s               ║\n", "EMAIL DO DESTINATÁRIO", aux->entrega->destinatario->email);
        printf("║ %-26s : %-56s               ║\n", "SEXO DO DESTINATÁRIO", aux->entrega->destinatario->sexo);
        printf("║ %-27s : %-56s               ║\n", "HORA DA DEVOLUÇÃO", aux->entrega->horaEntrega);
        printf("║ %-27s : %-56s               ║\n", "DATA DA DEVOLUÇÃO", aux->entrega->dataEntrega);
        printf("║ %-25s : %-56s               ║\n", "STATUS", aux->entrega->status);

        printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        aux = aux->prox;
    }
}