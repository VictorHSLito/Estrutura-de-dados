#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} Stack;

Stack* initializeStack(Stack *pilha) {
    /*Inicializa uma estrutura do tipo Stack,
    ela começara com o valor 0 e o ponteiro 
    próximo apontará para NULL*/

    pilha = malloc(sizeof(Stack));
    pilha->proximo = NULL;
    pilha->valor = 1;
    return pilha; // Após iniciar a pilha, retorna o endereço da mesma para o ponteiro topo
}

Stack* push(Stack *topo, int valor) {
    Stack *novo_no = malloc(sizeof(Stack)); // Cria um novo ponteiro do tipo Stack
    if (novo_no) {
        novo_no->valor = valor;
        novo_no->proximo = topo;
        return novo_no; // Retorna o endereço desse novo ponteiro para o topo da pilha
    }
    else {
        printf("Nao foi possivel alocar memoria");
    }
    return NULL;
}

Stack* pop(Stack **topo /*Passa o endereço do topo da pilha, se fosse *topo, estaria passando apenas a cópia*/) {
    if(*topo != NULL) {
        Stack *remover = *topo; // Cria um ponteiro que irá apontar para o topo, esse ponteiro é necessário pois iremos liberar o topo da pilha
        *topo = remover->proximo; // Faço com que o ponteiro remover, que está apontando para o topo, aponte para o próximo
        free(remover);
        return *topo;
    }
    
    else {
        printf("A pilha esta vazia!");
    }
    return NULL;
}

void imprimePilha(Stack *topo) {
    while (topo != NULL)
    {
        printf("\n\nEndereco do no: %p\n", topo);
        printf("Valor do no da pilha: %d\n", topo->valor);
        topo = topo->proximo;
    }
}

int main() {
    Stack *topo = NULL; // Inicializa um ponteiro que irá controlar o topo da pilha

    topo = initializeStack(topo);

    printf("Endereco do topo da pilha: %p\n", topo);
    printf("Valor do no do topo: %d\n", topo->valor);

    topo = push(topo, 2);
    topo = push(topo, 3);
    topo = push(topo, 4);

    printf("\nApos a operacao push:\n");
    printf("Endereco do topo da pilha: %p\n", topo);
    printf("Valor da no do topo: %d\n", topo->valor);

    topo = pop(&topo);

    printf("\nApos a operacao pop:\n");
    printf("Endereco do topo da pilha: %p\n", topo);
    printf("Valor da no do topo: %d\n", topo->valor);

    imprimePilha(topo);
    return 0;
}



