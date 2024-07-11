#include <stdio.h>
#include "transport.h"
#include <stdlib.h>


int main(){
    int op,op2;

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
                menu_organizacao();
                scanf("%d",&op2);
                switch (op2)
                {
                case 1:
                    lista_organizacao = add_no_fim_org(lista_organizacao);
                    break;
                case 4:
                    listar_clientes_org(lista_organizacao);
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