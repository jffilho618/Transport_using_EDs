#include <stdio.h>
#include "transport.h"
#include <stdlib.h>


int main(){
    int op,op2,op3,op4,op5;

    No_simples_clientes_organizacoes *lista_organizacao = cria_lista_organizacao();
    No_simples_clientes_pessoas *lista_pessoa = cria_lista_pessoa();

    do
    {
        menu_principal();
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            do
            {
                menu_cliente_pessoa();
                scanf("%d",&op2);
                switch (op2)
                {
                case 1:
                    lista_pessoa = add_no_fim_pessoa(lista_pessoa);
                    break;
                case 4:
                    if (lista_pessoa==NULL)
                    {
                        printf("NÃO HA CLIENTES CADASTRADOS !!\n\n");
                    }
                    else{
                        listar_clientes_pessoa(lista_pessoa);
                    }
                    break;
                case 5:
                    menu_consulta_cliente();
                    scanf("%d",&op3);
                    switch (op3)
                    {
                    case 1:
                        consulta_cliente_cpf(lista_pessoa);
                        break;
                    case 2:
                        consulta_cliente_nome(lista_pessoa);
                        break;
                    case 3:
                        menu_consulta_cliente_status();
                        scanf("%d",&op4);
                        switch (op4)
                        {
                        case 1:
                            consulta_cliente_status_ativo(lista_pessoa);
                            break;
                        case 2:
                            consulta_cliente_status_inativo(lista_pessoa);
                            break;
                        default:
                            break;
                        }
                        break;
                    }

                default:
                    break;
                }
            } while (op2!=0);
            break;
        
        case 2:
            do
            {
                menu_organizacao();
                scanf("%d",&op2);
                switch (op2)
                {
                case 1:
                    lista_organizacao = add_no_fim_org(lista_organizacao);
                    break;
                case 4:
                    if (lista_organizacao==NULL)
                    {
                        printf("NÃO HA ORGANIZAÇÕES CADASTRADOS !!\n\n");
                    }
                    else{
                        listar_clientes_org(lista_organizacao);
                    }
                    break;
                case 5:
                    menu_consulta_organizacao();
                    scanf("%d",&op5);
                    switch (op5)
                    {
                    case 1:
                        consulta_org_cnpj(lista_organizacao);
                        break;
                    case 2:
                        consulta_nome_org(lista_organizacao);
                        break;
                    case 3:
                        menu_consulta_organizacao_status();
                        scanf("%d",&op4);
                        switch (op4)
                        {
                        case 1:
                            consulta_org_status_ativo(lista_organizacao);
                            break;
                        case 2:
                            consulta_org_status_inativo(lista_organizacao);
                            break;
                        default:
                            break;
                        }
                        break;
                    }
                
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
