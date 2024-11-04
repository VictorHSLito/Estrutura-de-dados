/*Crie um programa que inicialize duas listas encadeadas e realize a concatenação destas listas*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int valor;
    struct Lista *prox;
} Lista;


Lista* inicializaLista(int tamanho) {
    Lista *inicio = NULL, *atual, *novo;

    for (int i = 0; i < tamanho; i++) {
        novo = malloc(sizeof(Lista));
        if (novo == NULL) {
            printf("Erro de alocação\n");
            exit(1);
        }
        novo->valor = rand() % 100;
        novo->prox = NULL;

        if (inicio == NULL) {
            inicio = novo;
        } else {
            atual->prox = novo;
        }
        atual = novo;
    }

    return inicio;
}

void imprimeLista(Lista *l) {
    while (l != NULL) {
        printf("%d -> ", l->valor);
        l = l->prox;
    }
    printf("NULL\n");
}

Lista* concatenaListas(Lista *l1, Lista *l2) {
    if (l1 == NULL) return l2;  
    if (l2 == NULL) return l1;  

    Lista *temp = l1;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = l2;

    return l1;
}

void liberaLista(Lista *l) {
    Lista *temp;
    while (l != NULL) {
        temp = l;
        l = l->prox;
        free(temp);
    }
}

int main() {
    
    Lista *lista1 = inicializaLista(5);
    Lista *lista2 = inicializaLista(3);

    
    printf("Lista 1:\n");
    imprimeLista(lista1);

    printf("Lista 2:\n");
    imprimeLista(lista2);

    
    Lista *listaConcatenada = concatenaListas(lista1, lista2);

    
    printf("Lista Concatenada:\n");
    imprimeLista(listaConcatenada);

    
    liberaLista(listaConcatenada);

    return 0;
}
