#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define QTDE_FILMES 10

typedef struct {
    int cod;
    char nome[100];
    char telefone[100];
} Cliente;

typedef struct {
    int cod;
    char nome[100];
    int alugado;
    Cliente cliente;
} Filme;

Filme filmes[QTDE_FILMES + 1];

void preencherFilmes() {
    char buffer[100];

    for (int i = 1; i <= QTDE_FILMES; i++) {
        sprintf(buffer, "Filme - %d", i);
        Filme filme;
        stpcpy(filme.nome, buffer);
        filme.cod = i;
        filme.alugado = 0;
        filmes[i] = filme;
    }
}
Cliente cadastrarCliente(int cod) {
    char nome[100];
    char telefone[100];
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);
    printf("Digite o telefone do cliente: ");
    scanf("%s", telefone);
    Cliente cliente;
    cliente.cod = cod;
    strcpy(cliente.nome, nome);
    strcpy(cliente.telefone, telefone);
    
    return cliente; 
}
void listarFilmes() {
    printf("---------- TODOS OS FILMES -----------\n\n");
    for (int i = 1; i <= QTDE_FILMES; i++) {
        char alugado[10];
        if (filmes[i].alugado == 1) {
            strcpy(alugado, "SIM");
        } else {
            strcpy(alugado, "NAO");
        }
        printf("CODIGO: %d - NOME: %s - ALUGADO: %s\n\n", filmes[i].cod, filmes[i].nome, alugado);
    }
}
void listarFilmesDisponiveis() {
    printf("---------- FILMES DISPONIVEIS -----------\n\n");
    for (int i = 1; i <= QTDE_FILMES; i++) {
        if (filmes[i].alugado == 0) {
            printf("CODIGO: %d - NOME: %s\n", filmes[i].cod, filmes[i].nome);
        } 
    }
}
void listarFilmesAlugados() {
    printf("----------- FILMES ALUGADOS ------------\n\n");
    for (int i = 1; i <= QTDE_FILMES; i++) {
        if (filmes[i].alugado == 1) {
            printf("-------------------------------------\n");
            printf("CODIGO: %d - NOME: %s\n\n", filmes[i].cod, filmes[i].nome);
            printf("CLIENTE - NOME: %s, TELEFONE: %s\n\n", filmes[i].cliente.nome, filmes[i].cliente.telefone);
            printf("-------------------------------------\n");
        }
    }
}
void alocarFilme() {
    int codigo;
    printf("Digite o codigo do filme: ");
    scanf("%d", &codigo);

    Cliente cliente = cadastrarCliente(codigo);

    int encontrado = 0;
    for (int i = 1; i <= QTDE_FILMES; i++) {
        if (filmes[i].cod == codigo) {
            filmes[i].alugado = 1;
            filmes[i].cliente = cliente;
            encontrado = 1;
        }
    }
    if (encontrado == 0) {
        printf("Nenhum filme encontrado com CODIGO: %d \n\n\n", codigo);
    } else {
        printf("Filme CODIGO: %d alugado com sucesso! \n\n\n", codigo);
    }
}
void devolverFilme() {
    int codigo;
    printf("Digite o codigo do filme: ");
    scanf("%d", &codigo);

    Cliente cliente;

    int encontrado = 0;
    for (int i = 1; i <= QTDE_FILMES; i++) {
        if (filmes[i].cod == codigo && filmes[i].alugado == 1) {
            filmes[i].alugado = 0;
            filmes[i].cliente = cliente;
            encontrado = 1;
        }
    }
    if (encontrado == 0) {
        printf("Nenhum filme alugado encontrado com CODIGO: %d \n\n\n", codigo);
    } else {
        printf("Filme CODIGO: %d, devolvido com successo! \n\n\n", codigo);
    }
}

int menu() {
    int op;

    fflush(stdin);

    printf("----------- L O C A D O R A ------------\n\n");

    printf("\n\t 1 - Alocar Filme ");
    printf("\n\t 2 - Devolver Filme");
    printf("\n\t 3 - Listar Todos os Filmes ");
    printf("\n\t 4 - Listar Filmes Disponiveis");
    printf("\n\t 5 - Listar Filmes Alugados ");
    printf("\n\n\t 6 - Sair \n\n\t ");

    scanf("%d", &op);

    return op;
}

void tela() {
    int sair = 0;
    while(sair == 0) {
        int op;
        op = menu();
        switch(op) {
            case 1: 
                alocarFilme();
            break;

            case 2: 
                devolverFilme();
            break;

            case 3: 
                listarFilmes();
            break;

            case 4:
                listarFilmesDisponiveis();
            break;

            case 5: 
                listarFilmesAlugados();
            break;

            case 6: 
                sair = 1;
            break;
        }
    }
}
int main() {
    preencherFilmes();
    tela();

    return 0;
}