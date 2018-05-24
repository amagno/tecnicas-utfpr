#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define QTDE_FILMES 10

typedef struct {
    int cod;
    char nome[100];
    int telefone;
} Cliente;

typedef struct {
    int cod;
    char nome[100];
    int alugado;
    Cliente cliente;
} Filme;

Filme filmes[QTDE_FILMES];

void preencherFilmes() {
    char *buffer;

    for (int i = 1; i <= QTDE_FILMES; i++) {
        sprintf(buffer, "Filme - %d", i);
        stpcpy(filmes[i].nome, buffer);
        filmes[i].cod = i;
        filmes[i].alugado = 0;
    }
}
void listarFilmes() {
    for (int i = 1; i <= QTDE_FILMES; i++) {
        printf("CODIGO: %d - NOME: %s\n", filmes[i].cod, filmes[i].nome);
    }
}
void listarFilmesDisponiveis() {
    printf("------ FILMES DISPONIVEIS ------");
    for (int i = 1; i <= QTDE_FILMES; i++) {
        if (filmes[i].alugado == 0) {
            printf("CODIGO: %d - NOME: %s\n", filmes[i].cod, filmes[i].nome);
        } 
    }
}
void listarFilmesAlugados() {
    printf("------ FILMES ALUGADOS ------");
    for (int i = 1; i <= QTDE_FILMES; i++) {
        if (filmes[i].alugado == 1) {
            printf("CODIGO: %d - NOME: %s\n", filmes[i].cod, filmes[i].nome);
        }
    }
}
void alocarFilme() {
    int codigo;
    printf("Digite o codigo do filme: ");
    scanf("%d", &codigo);

    if (codigo == 0) {
        return;
    }

    for (int i = 1; i <= QTDE_FILMES; i++) {
        if (filmes[i].cod == codigo) {
            filmes[i].alugado = 1;
        }
    }
}
Cliente cadastrarCliente() {
    char nome[100];
    printf("Digite o nome: ");
}
int menu() {
    int op;

    fflush(stdin);

    printf("----------- L O C A D O R A ------------\n\n");

    printf("\n\t 1 - Alocar Filme ");
    printf("\n\t 2 - Inserir Cliente ");
    printf("\n\t 3 - Listar Todos os Filmes ");
    printf("\n\t 4 - Listar Filmes Disponiveis");
    printf("\n\t 5 - Listar Filmes Alugados ");
    printf("\n\n\t 6 - Sair \n\n\t ");

    scanf("%d", &op);

    return op;
}

int main() {
    preencherFilmes();
    int op;

    op = menu();

    switch(op) {
        case 1: break;

        case 2: break;

        case 3: break;

        case 4:
            listarFilmes();
        break;

        case 5: break;

        case 6: break;
    }

    return 0;
}