#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* criar_no(int valor){
    No* novo = (No*)malloc(sizeof(No));
    if(!novo){
        printf("Erro ao alocar memória!");
        exit(EXIT_FAILURE);
    }

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void inserir(No** raiz, int valor){
    if(!*raiz){
        *raiz = criar_no(valor);
    } else {
        if(valor < (*raiz)->valor){ 
            inserir(&((*raiz)->esq), valor);
        } 
        else if(valor > (*raiz)->valor){ 
            inserir(&((*raiz)->dir), valor);
        } 
        else {
            printf("Valor já inserido na árvore!");
        }
    }
}

void travessia(No* raiz){
    if(raiz == NULL){
        return;
    }
    else{
        printf("%d -> ", raiz->valor);
        travessia(raiz->esq);
        travessia(raiz->dir);
    }
}

int main(){
    No* raiz = NULL;
    inserir(&raiz, 10);
    inserir(&raiz, 8);
    inserir(&raiz, 6);
    inserir(&raiz, 7);
    travessia(raiz);
    return 0;
}
