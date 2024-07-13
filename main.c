#include <stdio.h>
#include "transport.h"
#include <stdlib.h>


int main(){
    int op, op2, op3, op4, op5, op6, op7, op8, op9;
    int conta_entregas = 0;
    int pos_id = 0;
    int vetor_ids[100];

    No_simples_clientes_organizacoes *lista_organizacao = cria_lista_organizacao();
    No_simples_clientes_pessoas *lista_pessoa = cria_lista_pessoa();
    Fila *fila = fila_cria();
    No_simples_entregas *historico = cria_lista_entregas();
    Pilha_nao_entregues *pilha_nao_entregues = criaPilha();
    No_simples_entregas *lista_devolucao = cria_lista_entregas();


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
                case 2: 
                    if (lista_pessoa == NULL){
                        printf("Não há clientes cadastrados!\n");
                    }

                    else{ 
                        menu_editar_status_cliente_avulso(); 
                        scanf("%d", &op6);                         
                        switch(op6){ 
                            do{
                            case 1: 
                               //pesquisar pelo CPF 
                               editar_status_cliente_avulso(lista_pessoa, 1);
                               break; 
                            case 2: 
                               //Pesquisar pelo Nome  
                               editar_status_cliente_avulso(lista_pessoa, 2);
                               break; 
                            case 0: 
                               break;   
                            default: 
                               printf("Entrada inválida"); 
                               break; 
                            
                            }while(op6 != 0);

                        }
                    }
                    break;    
                    
                case 3:
                    if (lista_pessoa == NULL){
                        printf("Não há clientes cadastrados!\n");
                    }

                    else{
                        editar_cliente_avulso(lista_pessoa);
                    }

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
                    break;
                
                case 7:
                    fila = realizar_postagem_por_pessoa(fila, lista_pessoa, &conta_entregas, vetor_ids, &pos_id);
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
                case 2: 
                    if (lista_organizacao == NULL) {
                        printf("NÃO HÁ ORGANIZAÇÕES CADASTRADAS !!\n\n");
                    } else { 
                        do{
                        menu_editar_status_cliente_Organizacao(); 
                        
                            scanf("%d", &op7);                         
                            switch (op7) { 
                                case 1: 
                                    // Pesquisar pelo CNPJ 
                                    editar_status_cliente_organizacao(lista_organizacao, 1);
                                    break; 
                                case 2: 
                                    // Pesquisar pelo Nome Fantasia 
                                    editar_status_cliente_organizacao(lista_organizacao, 2);
                                    break; 
                                case 0: 
                                    break;   
                                default: 
                                    printf("Entrada inválida\n"); 
                                    break; 
                            }
                        } while (op7 != 0);
                    }
                    break;
                    

                case 3:
                    if (lista_organizacao == NULL){
                        printf("Não há clientes cadastrados!\n");
                    }

                    else{
                        editar_cliente_organizacao(lista_organizacao);
                    }

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

        case 3:
            do
            {
                menu_entregas();
                scanf("%d",&op8);
                switch (op8)
                {
                case 1:
                    imprimir_fila(fila);
                    break;

                case 2:
                    realizar_entrega(fila, &conta_entregas,&historico, &pilha_nao_entregues, &lista_devolucao);
                    break;

                case 3:
                    historico_enviados_clientes(historico);
                    break;
                
                case 4:
                    historico_recebidos_clientes(historico);
                    break;

                case 7:
                    historico_devolucao(lista_devolucao);
                    break;
                case 0:
                    break;

                default:
                    printf("Entrada inválida!\n");
                    break;
                }
                
            } while (op8 != 0);
            break;

        default:
            break;
        }
        
    } while (op!=0);
    
    return 0;
}
