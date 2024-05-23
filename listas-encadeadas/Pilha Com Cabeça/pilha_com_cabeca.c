// - A lista começa com uma célula cabeça que não contém dados úteis 
//  (inicializada no main).
// - O ponteiro da lista (`lst`) sempre aponta para essa célula cabeça, 
//  que por sua vez aponta para a primeira célula com dados.

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int conteudo;
    struct Celula *seg;
} Celula;

void insere(Celula *lst, int valor) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->conteudo = valor;
    nova->seg = NULL;
    Celula *p = lst;
    while (p->seg != NULL) {
        p = p->seg;
    }
    p->seg = nova;
}

void removePilha(Celula *lst) {
    if (lst->seg == NULL) return;

    Celula *p = lst;

    if (p->seg->seg == NULL) {
        free(p->seg);
        p->seg = NULL;
        return;
    }

    while (p->seg->seg != NULL) {
        p = p->seg;
    }

    free(p->seg);
    p->seg = NULL;
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
  removePilha(&cabeca);
  removePilha(&cabeca);

  // Impressão
  imprime(&cabeca);
  
  return 0;
}