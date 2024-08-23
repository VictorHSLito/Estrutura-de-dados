#include <stdio.h>
#include <stdbool.h>

#define MAX 50          // Define o tamanho máximo da lista
#define INVALIDO -1     // Define um valor constante para indicar uma posição inválida

typedef int TIPOCHAVE;  // Define um tipo de dado para a chave dos registros

// Estrutura que representa um registro com uma chave
typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

// Estrutura que representa um elemento da lista, contendo um registro e um ponteiro para o próximo elemento
typedef struct {
    REGISTRO reg;
    int prox;
} ELEMENTO;

// Estrutura que representa a lista em si, com um array de elementos, um índice para o início da lista e outro para a posição disponível
typedef struct {
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
} LISTA;

// Inicializa a lista, configurando os índices e ligando todos os elementos disponíveis em uma lista encadeada
void iniciaLista(LISTA *l) {
    int i;
    for (i = 0; i < MAX - 1; i++) {
        l->A[i].prox = i + 1;  // Conecta cada elemento ao próximo
    }
    l->A[MAX-1].prox = INVALIDO; // O último elemento aponta para inválido
    l->inicio = INVALIDO;        // A lista começa vazia
    l->dispo = 0;                // O primeiro elemento disponível é o primeiro do array
}

// Retorna o tamanho atual da lista
int tamanho(LISTA *l) {
    int i = l->inicio;
    int tam = 0;
    while (i != INVALIDO) {
        tam++;
        i = l->A[i].prox;  // Avança para o próximo elemento
    }
    return tam;
}

// Exibe todos os elementos da lista
void exibirlista(LISTA *l) {
    int i = l->inicio;
    printf("Lista: \" ");
    while (i != INVALIDO) {
        printf("%i ", l->A[i].reg.chave);  // Imprime a chave do elemento atual
        i = l->A[i].prox;  // Avança para o próximo elemento
    }
    printf("\"\n");
}

// Busca sequencial por um elemento na lista ordenada por chave
int buscaSequencialOrd(LISTA *l, TIPOCHAVE ch) {
    int i = l->inicio;
    while (i != INVALIDO && l->A[i].reg.chave < ch) {
        i = l->A[i].prox;  // Avança para o próximo elemento enquanto a chave for menor que a buscada
    }
    if (i != INVALIDO && l->A[i].reg.chave == ch) return i;  // Retorna o índice se encontrou
    else return INVALIDO;  // Retorna inválido se não encontrou
}

// Obtém o próximo elemento disponível para inserção
int obterEle(LISTA *l) {
    int resultado = l->dispo;
    if (l->dispo != INVALIDO)
        l->dispo = l->A[l->dispo].prox;  // Atualiza o índice do próximo disponível
    return resultado;
}

// Insere um elemento na lista de forma ordenada
bool inserirElemListaOrd(LISTA *l, REGISTRO reg) {
    if (l->dispo == INVALIDO) return false;  // Verifica se há espaço disponível
    int anterior = INVALIDO;
    int i = l->inicio;
    TIPOCHAVE ch = reg.chave;
    while ((i != INVALIDO) && (l->A[i].reg.chave < ch)) {
        anterior = i;
        i = l->A[i].prox;  // Avança para encontrar a posição correta para inserção
    }
    if (i != INVALIDO && l->A[i].reg.chave == ch) return false;  // Evita duplicatas
    i = obterEle(l);  // Obtém um espaço livre para o novo elemento
    if (anterior == INVALIDO) {
        l->A[i].prox = l->inicio;  // Insere no início da lista
        l->inicio = i;
    } else {
        l->A[i].prox = l->A[anterior].prox;  // Insere no meio ou final da lista
        l->A[anterior].prox = i;
    }
    return true;
}

// Devolve o elemento ao final da lista de disponíveis após exclusão
void devolver(LISTA *l, int j) {
    l->A[j].prox = l->dispo;
    l->dispo = j;
}

// Exclui um elemento da lista
bool excluirElemLista(LISTA *l, TIPOCHAVE ch) {
    int anterior = INVALIDO;
    int i = l->inicio;
    while ((i != INVALIDO) && l->A[i].reg.chave < ch) {
        anterior = i;
        i = l->A[i].prox;  // Avança para encontrar o elemento a ser excluído
    }
    if (i == INVALIDO || l->A[i].reg.chave != ch) return false;  // Verifica se encontrou o elemento
    if (anterior == INVALIDO) l->inicio = l->A[i].prox;  // Exclui o primeiro elemento
    else l->A[anterior].prox = l->A[i].prox;  // Exclui um elemento no meio ou final da lista
    devolver(l, i);  // Devolve o espaço liberado à lista de disponíveis
    return true;
}

// Reinicia a lista, voltando ao estado inicial
void reiniciarLista(LISTA *l) {
    iniciaLista(l);
}
