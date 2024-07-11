typedef struct entrega
{
    char descricao[50];
    int  id;
    char dataEntrega[15];
    char horaEntrega[15];
    char status[15];
    int score;
}Entrega;
typedef struct cliente_organizacao
{
    char nome[50];
    char cnpj[15];
    char telefone[15];
    char endereco[50];
    char email[50];
    char status_organizacao[12];
    int conta_entregas;
    Entrega *entregas;
}Cliente_organizacao;

typedef struct cliente_pessoa
{
    char nome[50];
    char cpf[15];
    char telefone[15];
    char endereco[50];
    char email[50];
    char sexo[10];
    char status_cliente[12];
    int conta_entregas;
    Entrega *entregas;

}Cliente_pessoa;

typedef struct no_simples_clientes_pessoas
{
    Cliente_pessoa cliente;
    struct no_simples_clientes_pessoas *prox;

}No_simples_clientes_pessoas;

typedef struct no_simples_clientes_organizacoes
{
    Cliente_organizacao cliente;
    struct no_simples_clientes_organizacoes *prox;
}No_simples_clientes_organizacoes;

typedef struct rota{
    Entrega entrega;
    struct rota *prox;
}Rota;


typedef struct fila{
    int info;
    struct rota *inicio;
    struct rota *fim;
}Fila;


Fila* fila_cria(void);
void fila_insere(Fila* f, float v);
float fila_retira(Fila** f);
int fila_vazia(Fila* f);
void fila_libera(Fila* f);

No_simples_clientes_pessoas *cria_lista_pessoa();
No_simples_clientes_pessoas *add_no_fim_pessoa(No_simples_clientes_pessoas *lista);
void Adicionar_cliente_pessoa(No_simples_clientes_pessoas *lista);
void listar_clientes_pessoa(No_simples_clientes_pessoas *lista);

No_simples_clientes_organizacoes *cria_lista_organizacao();
No_simples_clientes_organizacoes *add_no_fim_org(No_simples_clientes_organizacoes *lista);
void Adicionar_cliente_organizacao();
void Exibir_Cliente_organizacao(No_simples_clientes_organizacoes *lista, char cnpj);






