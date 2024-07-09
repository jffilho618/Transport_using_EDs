typedef struct cliente
{
    char nome[50];
    char cpf[15];
    char telefone[15];
    char endereco[50];
    char email[50];
    char dataNascimento[15];
    char sexo[10];
}Cliente;

typedef struct entrega
{
    char nome[50];
    char endereco[50];
    char dataEntrega[15];
    char horaEntrega[15];
    char status[15];
}Entrega;

typedef struct no_simples
{
    Cliente cliente;
    struct no_simples *prox;

}No_Simples;

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
