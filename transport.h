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

typedef struct no_simples
{
    Cliente cliente;
    struct no_simples *prox;

}No_Simples;

typedef struct no{
    int info;
    struct no *prox;
}No;


typedef struct fila{
    int info;
    struct no *inicio;
    struct no *fim;
}Fila;


Fila* fila_cria(void);
void fila_insere(Fila* f, float v);
float fila_retira(Fila** f);
int fila_vazia(Fila* f);
void fila_libera(Fila* f);
