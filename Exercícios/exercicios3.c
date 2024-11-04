/*Crie um programa que inicialize uma lista encadeada e realize a destruição desta lista em tempo de execução.*/

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
            printf("Erro de alocacao\n");
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


void destroiLista(Lista *l) {
    Lista *temp;
    while (l != NULL) {
        temp = l;
        l = l->prox;
        free(temp);
    }
    printf("Lista destruida com sucesso.\n");
}

int main() {

    Lista *lista = inicializaLista(5);

    
    printf("Lista antes da destruicao:\n");
    imprimeLista(lista);

    
    destroiLista(lista);

    return 0;
}
