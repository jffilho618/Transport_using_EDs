typedef struct cliente_organizacao
{
    char nome[50];
    char cnpj[15];
    char telefone[15];
    char endereco[50];
    char email[50];
    char status_organizacao[12];
    int conta_entregas;
    //Entrega *entregas;
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
    //Entrega *entregas;

}Cliente_pessoa;
typedef struct entrega
{
    int  id;
    char *dataPostagem;
    char *horaPostagem;
    char dataEntrega[15];
    char horaEntrega[15];
    char status[15];
    int score;
    Cliente_pessoa *remetente_pessoa;
    Cliente_pessoa *destinatario;
    Cliente_organizacao *remetente_cliente_organizacao;
}Entrega;


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

typedef struct no{
    Entrega *entrega;
    struct no *prox;
}No;


typedef struct fila{
    int info;
    struct no *inicio;
    struct no *fim;
}Fila;


void menu_principal();
void menu_organizacao();
void menu_cliente_pessoa();
void menu_consulta_cliente();
void menu_consulta_cliente_status();
void menu_consulta_organizacao();
void menu_consulta_organizacao_status();
void menu_entregas();


Fila* fila_cria(void);
void fila_insere_ordenado(Fila* f, Entrega *entrega);
void fila_insere(Fila* f, float v);
float fila_retira(Fila** f);
int fila_vazia(Fila* f);
void fila_libera(Fila* f);
void imprimir_fila(Fila *f);

No_simples_clientes_pessoas *cria_lista_pessoa();
No_simples_clientes_pessoas *add_no_fim_pessoa(No_simples_clientes_pessoas *lista);
void listar_clientes_pessoa(No_simples_clientes_pessoas *lista);
void consulta_cliente_cpf(No_simples_clientes_pessoas *lista);
void consulta_cliente_nome(No_simples_clientes_pessoas *lista);
void consulta_cliente_status_inativo(No_simples_clientes_pessoas *lista);
void consulta_cliente_status_ativo(No_simples_clientes_pessoas *lista);
void menu_editar_cliente();
void editar_cliente_avulso(No_simples_clientes_pessoas *lista);
Fila *realizar_postagem_por_pessoa(Fila *fila, No_simples_clientes_pessoas *lista, int *conta_entregas, int vet[], int *n);


No_simples_clientes_organizacoes *cria_lista_organizacao();
No_simples_clientes_organizacoes *add_no_fim_org(No_simples_clientes_organizacoes *lista);
void listar_clientes_org(No_simples_clientes_organizacoes *lista);
void consulta_org_cnpj(No_simples_clientes_organizacoes *lista);
void consulta_nome_org(No_simples_clientes_organizacoes *lista);
void consulta_org_status_inativo(No_simples_clientes_organizacoes *lista);
void consulta_org_status_ativo(No_simples_clientes_organizacoes *lista);
void menu_editar_organizacao();
void editar_cliente_organizacao(No_simples_clientes_organizacoes *lista);


void menu_editar_cliente();
void editar_cliente_avulso(No_simples_clientes_pessoas *lista);

void menu_editar_status_cliente_avulso(); 
void editar_status_cliente_avulso(No_simples_clientes_pessoas *lista, int opcao); 

void menu_editar_status_cliente_Organizacao(); 
void editar_status_cliente_organizacao(No_simples_clientes_organizacoes *lista, int opcao);

int sorteia_ids(int vet[], int *n);