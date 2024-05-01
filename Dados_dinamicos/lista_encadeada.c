#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char nome[20];
    int idade;
    struct No* prox;
}No;

No* criar_no(char nome[], int idade){
    No* novo = (No*)malloc(sizeof(No));
    if(!novo){
        printf("Erro ao alocar memória!");
        exit(EXIT_FAILURE);
    }

    strncpy((novo->nome), nome, sizeof(novo->nome));
    novo->idade = idade;
    novo->prox = NULL;
    return novo;
}

void inserir_no_inicio(No** cabeca, char nome[], int idade){
    No* novo = criar_no(nome, idade);
    if (!*cabeca) {
        *cabeca = novo;
    } 
    else {
        novo->prox = *cabeca;
        *cabeca = novo;
    }
}

void inserir_no_fim(No** cabeca, char nome[], int idade){
    No* novo = criar_no(nome, idade);
    if(!*cabeca){
        *cabeca = novo;
        return;
    }

    No* auxiliar = *cabeca;
    while(auxiliar->prox != NULL){
        auxiliar = auxiliar->prox;
    }

    auxiliar->prox = novo;

}


void imprimir_lista(No* cabeca){
    No* print = cabeca;
    if(cabeca == NULL){
        printf("Não há nada para listar");
        return;
    }

    while(print != NULL){
        printf("Nome: %s - Idade: %d\n", print->nome, print->idade);
        print = print->prox;
    }
}

int main() {

    No* minha_lista = NULL;
    inserir_no_fim(&minha_lista, "vitoria", 13);
    inserir_no_fim(&minha_lista, "maria", 17);
    inserir_no_fim(&minha_lista, "frederico", 79);
    inserir_no_inicio(&minha_lista, "Erik", 19);
    inserir_no_inicio(&minha_lista, "gabriel", 10);
    inserir_no_inicio(&minha_lista, "danilo", 20);
    inserir_no_inicio(&minha_lista, "malu", 46);
    inserir_no_inicio(&minha_lista, "joão", 23);
    imprimir_lista(minha_lista);

    return 0;
}