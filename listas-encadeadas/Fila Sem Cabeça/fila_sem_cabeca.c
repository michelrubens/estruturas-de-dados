// - A lista começa diretamente com a primeira célula contendo dados.
// - O ponteiro da lista (`lst`) aponta diretamente para a primeira célula com dados.

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int conteudo;
    struct Celula *seg;
} Celula;

void insere(Celula **lst, int valor) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->conteudo = valor;
    nova->seg = NULL;
    if (*lst == NULL) {
        *lst = nova;
    } else {
        Celula *p = *lst;
        while (p->seg != NULL) {
            p = p->seg;
        }
        p->seg = nova;
    }
}

void removeFila(Celula **lst) {
    if (*lst != NULL) {
        Celula *temp = *lst;
        *lst = (*lst)->seg;
        free(temp);
    }
}

void imprime(Celula *lst) {
    Celula *p;
    for (p = lst; p != NULL; p = p->seg) {
        printf("%d ", p->conteudo);
    }
    printf("\n");
}

int main() {
  Celula *listaSemCabeca = NULL;

  // Inserção
  insere(&listaSemCabeca, 1);
  insere(&listaSemCabeca, 2);
  insere(&listaSemCabeca, 3);
  insere(&listaSemCabeca, 4);
  insere(&listaSemCabeca, 5);

  // Impressão
  imprime(listaSemCabeca);

  // Remoção
  removeFila(&listaSemCabeca);
  removeFila(&listaSemCabeca);

  // Impressão
  imprime(listaSemCabeca);

  return 0;
}