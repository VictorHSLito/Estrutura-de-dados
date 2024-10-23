#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int frente;
    int tras;
} Fila;

void initializeQueue(Fila *f) { // Inicializa a fila com os elementos frente e trás apontando para -1
    f->frente = -1;
    f->tras = -1;
}

int isFull(Fila *f) { // Verifica se a fila está cheia
    if (f->tras == MAX - 1) 
        return 1;
    else return 0;
}

int isEmpty(Fila *f) { // Verifica se a fila está vazia
    if (f->frente == -1 || f->frente > f->tras)
        return 1;
    else return 0;
}

void enqueue(Fila *f, int value) {
    if (isFull(f)) {
        printf("A fila esta cheia!");
    }
    else {
        if (f->frente == -1) {
            f->frente = 0;
        }
        f->tras++;
        f->itens[f->tras] = value;
        printf("%d inserido na fila.\n", value);
    }
}

int dequeue(Fila *f) {
    if(isEmpty(f)) {
        printf("A fila esta vazia!");
        return -1;
    }
    else {
        int value = f->itens[f->frente];
        f->frente++;
        if (f->frente > f->tras) {
            f->frente = f->tras = -1;
        }
        return value;
    }
}

int peek(Fila* f) {
    if (isEmpty(f)) {
        printf("A fila está vazia!\n");
        return -1;
    } else {
        return f->itens[f->frente];
    }
}

int main () {
    Fila f;
    initializeQueue(&f);

    enqueue(&f, 1);
    enqueue(&f, 2);
    enqueue(&f, 3);
    enqueue(&f, 4);
    enqueue(&f, 5);

    printf("Elemento removido: %d\n", dequeue(&f));
    printf("Elemento na frente da fila: %d\n", peek(&f));

    return 0;
}