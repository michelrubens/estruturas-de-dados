// - A lista começa diretamente com a primeira célula contendo dados.
// - O ponteiro da lista (`lst`) aponta diretamente para a primeira célula com dados.

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int conteudo;
    struct Celula *seg;
} Celula;

void insere(Celula **inicio, Celula **fim, int valor) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->conteudo = valor;
    nova->seg = NULL;
    if (*fim == NULL) {
        *inicio = nova;
        *fim = nova;
    } else {
        (*fim)->seg = nova;
        *fim = nova;
    }
}

int removeFila(Celula **inicio, Celula **fim) {
    if (*inicio == NULL) {
        return -1; // Fila vazia
    }
    int valorRemovido = (*inicio)->conteudo;
    Celula *temp = *inicio;
    *inicio = (*inicio)->seg;
    if (*inicio == NULL) {
        *fim = NULL;
    }
    free(temp);
    return valorRemovido;
}

void imprime(Celula *inicio) {
    Celula *p;
    for (p = inicio; p != NULL; p = p->seg) {
        printf("%d ", p->conteudo);
    }
    printf("\n");
}

int main() {
    Celula *inicio = NULL;
    Celula *fim = NULL;

    // Inserção
    insere(&inicio, &fim, 1);
    insere(&inicio, &fim, 2);
    insere(&inicio, &fim, 3);
    insere(&inicio, &fim, 4);
    insere(&inicio, &fim, 5);

    // Impressão
    imprime(inicio);

    // Remoção
    int removido1 = removeFila(&inicio, &fim);
    int removido2 = removeFila(&inicio, &fim);

    // Impressão
    imprime(inicio);

    // Exibe os valores removidos
    printf("Removido: %d\n", removido1);
    printf("Removido: %d\n", removido2);

    return 0;
}
