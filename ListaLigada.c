#include <stdio.h>
#include <stdbool.h>

#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct 
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO reg;
    int prox;
} ELEMENTO;

typedef struct {
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
} LISTA;

void iniciaLista(LISTA *l) {
    int i;
    for (i = 0; i < MAX - 1; i++) {
        l->A[i].prox = i + 1;
    }
    l->A[MAX-1].prox = INVALIDO;
    l->inicio = INVALIDO;
    l->dispo = 0;
}

int tamanho(LISTA *l) {
    int i = l->inicio;
    int tam = 0;
    while (i != INVALIDO)
    {
       tam++;
       i = l->A[i].prox;
    }

    return tam;
    
}

void exibirlista(LISTA *l) {
    int i = l->inicio;
    printf("Lista: \" ");

    while (i != INVALIDO) 
    {
        printf("%i ", l->A[i].reg.chave);
        i = l->A[i].prox;
    }
    printf("\"\n");
}