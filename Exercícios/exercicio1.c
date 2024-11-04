/*Crie um programa que inicialize uma lista encadeada e realize uma busca para verificar se um item x está nesta lista.*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 7

typedef struct Lista
{
    int valor;
    struct Lista *prox;
} Lista;

// Função para inicializar a lista encadeada
Lista* iniciaLista() {
    Lista *inicio = NULL, *atual, *novo;

    for (int i = 0; i < TAM; i++) {
        novo = malloc(sizeof(Lista));
        if (novo == NULL) {
            printf("Erro de alocação\n");
            exit(1);
        }
        novo->valor = rand() % 100;
        novo->prox = NULL;

        if (inicio == NULL) {  // Primeiro elemento
            inicio = novo;
        } else {  // Elementos subsequentes
            atual->prox = novo;
        }
        atual = novo;
    }

    return inicio;
}

// Função para imprimir a lista encadeada
void imprimeLista(Lista *l) {
    while (l != NULL) {
        printf("%d -> ", l->valor);
        l = l->prox;
    }
    printf("NULL\n");
}

void procuraElemento(int valor, Lista *l) {
    while (l != NULL) {
        if (valor == l->valor) {
            printf("O valor %d esta contido na lista!\n", valor);
            return;
        }
        l = l->prox;
    }
    printf("Esse valor nao esta foi encontrado na lista!\n");
    
}

int main() {
    int valor;
    Lista *l = iniciaLista();

    printf("Digite um valor: ");
    scanf("%d", &valor);
    procuraElemento(valor, l);

    imprimeLista(l);  

    Lista *temp;
    while (l != NULL) {
        temp = l;
        l = l->prox;
        free(temp);
    }

    return 0;
}