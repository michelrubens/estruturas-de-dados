// - A lista começa com uma célula cabeça que não contém dados úteis (inicializada no main).
// - O ponteiro da lista (`lst`) sempre aponta para a célula cabeça, que aponta para a 1ª célula com dados.

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int conteudo;
    struct Celula *seg;
} Celula;

void insere(Celula *lst, int valor) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro ao alocar memória\n");
    }
    nova->conteudo = valor;
    nova->seg = lst->seg;
    lst->seg = nova;
}

int removePilha(Celula *lst) {
    if (lst->seg == NULL) return -1; // retorna -1 como sinal de erro

    Celula *p = lst->seg;
    int valorRemovido = p->conteudo;
    lst->seg = p->seg; // Cabeça aponta para a próxima célukla
    free(p->seg);

    return valorRemovido;
}

void imprime(Celula *lst) {
    Celula *p;
    for (p = lst->seg; p != NULL; p = p->seg) {
        printf("%d ", p->conteudo);
    }
    printf("\n");
}

int main() {
    Celula cabeca;
    cabeca.seg = NULL;

    // Inserção
    insere(&cabeca, 1);
    insere(&cabeca, 2);
    insere(&cabeca, 3);
    insere(&cabeca, 4);
    insere(&cabeca, 5);

    // Impressão
    imprime(&cabeca);

    // Remoção
    int removido1 = removePilha(&cabeca);
    int removido2 = removePilha(&cabeca);

    // Impressão
    imprime(&cabeca);

    // Exibe os valores removidos
    printf("Removido: %d\n", removido1);
    printf("Removido: %d\n", removido2);
    
    return 0;
}