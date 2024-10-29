#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct stack {
    int size[MAX];
    int tos; // Tos é topo da pilha (Top of Stack)
    int bos;  // Bos é o final da pilha (Bottom of Stack)
} stack;

void initializeStack(stack *s);
void push(int i, stack *s);
int pop(stack *s);

int main() {
    stack s;
    initializeStack(&s);

    printf("Digite 5 elementos: ");
    for (int i = 0; i < 5; i++) {
        int aux;
        scanf("%d", &aux);
        push(aux, &s);
    }

    for (int i = 4; i >= 0; i--) {
        printf("Elemento %d\n", pop(&s));
    }
    return 0;    
}

void initializeStack(stack *s) {
    s->tos = 0;
    s->bos = 0;
}

void push(int i, stack *s) {
    if (s->tos >= MAX) {
        printf("Pilha cheia!\n");
        return;
    }
    s->size[s->tos] = i;
    s->tos++;
}

int pop(stack *s) {
    if (s->tos == 0) {
        printf("Pilha vazia!\n");
        return 0;
    }
    s->tos--;
    return s->size[s->tos];
}
