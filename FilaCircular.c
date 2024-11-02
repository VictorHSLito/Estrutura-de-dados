#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Tamanho máximo da fila circular

typedef struct {
    int itens[MAX];
    int frente; // Índice do início da fila
    int tras;   // Índice do fim da fila
} FilaCircular;

// Função para inicializar a fila circular
void inicializarFila(FilaCircular* f) {
    f->frente = -1;
    f->tras = -1;
}

// Verifica se a fila está cheia
int isFull(FilaCircular* f) {
    return ((f->tras + 1) % MAX == f->frente);
}

// Verifica se a fila está vazia
int isEmpty(FilaCircular* f) {
    return (f->frente == -1);
}

// Função para adicionar um elemento na fila circular
void enqueue(FilaCircular* f, int valor) {
    if (isFull(f)) {
        printf("A fila está cheia! Não é possível adicionar %d.\n", valor);
        return;
    }

    if (isEmpty(f)) {
        f->frente = 0; // Definir o início se estiver vazia
    }

    f->tras = (f->tras + 1) % MAX; // Move para a próxima posição circular
    f->itens[f->tras] = valor;
    printf("%d inserido na fila.\n", valor);
}

// Função para remover um elemento da fila circular
int dequeue(FilaCircular* f) {
    if (isEmpty(f)) {
        printf("A fila está vazia! Não é possível remover elementos.\n");
        return -1;
    }

    int valor = f->itens[f->frente];
    if (f->frente == f->tras) { // Quando remover o último elemento
        f->frente = f->tras = -1;
    } else {
        f->frente = (f->frente + 1) % MAX; // Move para a próxima posição circular
    }

    return valor;
}

// Função para ver o primeiro elemento da fila
int peek(FilaCircular* f) {
    if (isEmpty(f)) {
        printf("A fila está vazia!\n");
        return -1;
    } else {
        return f->itens[f->frente];
    }
}

// Função principal
int main() {
    FilaCircular f;
    inicializarFila(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);
    enqueue(&f, 40);
    enqueue(&f, 50);

    printf("Elemento removido: %d\n", dequeue(&f));
    printf("Elemento na frente da fila: %d\n", peek(&f));

    enqueue(&f, 60); // Reinsere quando há espaço disponível

    printf("Estado atual da fila:\n");
    while (!isEmpty(&f)) {
        printf("Elemento: %d\n", dequeue(&f));
    }

    return 0;
}
