#include <stdio.h>
#include "transport.h"
#include <stdlib.h>


int main(){
    int op,op2;

    No_simples_clientes_organizacoes *lista_organizacao = cria_lista_organizacao();
    No_simples_clientes_pessoas *lista_pessoa = cria_lista_pessoa();

    do
    {
        printf("[1] MENU CLIENTE PESSOA\n");
        printf("[2] MENU CLIENTE ORGANIZACAO\n");
        printf("[3] SOBRE\n");
        printf("[0] SAIR\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            do
            {
                printf("[1] ADICINOAR CLIENTE PESSOA\n");
                printf("[2] REMOVER CLIENTE PESSOA\n");
                printf("[3] EDITAR CLIENTE PESSOA\n");
                printf("[4] LISTAR CLIENTES PESSOA\n");
                printf("[5] CONSULTAR CLIENTE PESSOA\n");
                printf("[6] CONSULTAR HISTORICO DE PEDIDOS DO CLIENTE PESSOA\n");
                printf("[7] REALIZAR POSTAGEM POR PESSOA\n");
                printf("[0] SAIR\n");
                scanf("%d",&op2);
                switch (op2)
                {
                case 1:
                    lista_pessoa = add_no_fim_pessoa(lista_pessoa);
                    break;
                case 4:
                    listar_clientes_pessoa(lista_pessoa);
                    break;

                default:
                    break;
                }
            } while (op2!=0);
            break;
        
        case 2:
            do
            {
                printf("[1] ADICINOAR CLIENTE ORGANIZACAO\n");
                printf("[2] REMOVER CLIENTE ORGANIZACAO\n");
                printf("[3] EDITAR CLIENTE ORGANIZACAO\n");
                printf("[4] LISTAR CLIENTES ORGANIZACAO\n");
                printf("[5] CONSULTAR CLIENTE ORGANIZACAO\n");
                printf("[6] CONSULTAR HISTORICO DE PEDIDOS DO CLIENTE ORGANIZACAO\n");
                printf("[7] REALIZAR POSTAGEM POR ORGANIZACAO\n");
                printf("[0] SAIR\n");
                scanf("%d",&op2);
                switch (op2)
                {
                case 1:
                    lista_organizacao = add_no_fim_org(lista_organizacao);
                    break;
                case 4:
                    listar_clientes_organizacao(lista_organizacao);
                    break;
                
                default:
                    break;
                }
            } while (op2!=0);
            break;
        
        default:
            break;
        }
    } while (op!=0);
    
    return 0;
}