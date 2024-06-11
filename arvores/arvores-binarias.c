/* Complexidade:
  - Melhor caso: O(log n)
  - Pior caso: O(n) (Lista encadeada)
*/

#include <stdio.h>
#include <stdlib.h>

struct cel {
  int chave;
  int valor;
  struct cel *esq;
  struct cel *dir;
}; typedef struct cel NoArvore;

typedef NoArvore *arvore;

arvore criarNo(int chave, int valor) {
  arvore novoNo = (arvore)malloc(sizeof(NoArvore));
  novoNo->chave = chave;
  novoNo->valor = valor;
  novoNo->esq = NULL;
  novoNo->dir = NULL;
  return novoNo;
}

arvore inserir(arvore r, NoArvore *novoNo) {
  NoArvore *f, *p;
  if (r == NULL) return novoNo;
  f = r;
  while (f != NULL) {
    p = f;
    if (f->chave > novoNo->chave) f = f->esq;
    else f = f->dir;
  }
  if (p->chave > novoNo->chave) p->esq = novoNo;
  else p->dir = novoNo;
  return r;
}

arvore removerRaiz(arvore r) {
  if (r == NULL) return NULL;
  NoArvore *p, *q;
  if (r->esq == NULL) q = r->dir;
  else {
    p = r;
    q = r->esq;
    while (q->dir != NULL) {
      p = q;
      q = q->dir;
    }
    /* q é o nó anterior a r na ordem e-r-d */
    /* p é o pai de q */
    if (p != r) {
      p->dir = q->esq;
      q->esq = r->esq;
    }
    q->dir = r->dir;
  }
  free(r);
  return q;
}

arvore remover(arvore r, int chave) {
  // Se a árvore estiver vazia, simplesmente retorna NULL
  if (r == NULL) return NULL;

  // Se a chave do nó atual for maior que a chave a ser removida,
  // chama recursivamente a função para a subárvore esquerda
  if (r->chave > chave) {
    r->esq = remover(r->esq, chave);
  }
  // Se a chave do nó atual for menor que a chave a ser removida,
  // chama recursivamente a função para a subárvore direita
  else if (r->chave < chave) {
    r->dir = remover(r->dir, chave);
  }
  // Se a chave do nó atual for igual à chave a ser removida,
  // este é o nó que deve ser removido
  else {
    NoArvore *p;
    // Caso 1: O nó a ser removido não tem filho esquerdo
    if (r->esq == NULL) {
      p = r->dir;
      free(r);  // Libera a memória do nó atual
      return p; // Retorna o filho direito para ligar ao pai do nó removido
    }
    // Caso 2: O nó a ser removido não tem filho direito
    else if (r->dir == NULL) {
      p = r->esq;
      free(r);  // Libera a memória do nó atual
      return p; // Retorna o filho esquerdo para ligar ao pai do nó removido
    }
    // Caso 3: O nó a ser removido tem ambos os filhos
    else {
      p = r;
      NoArvore *q = r->esq;
      // Encontra o maior nó na subárvore esquerda (predecessor in-order)
      while (q->dir != NULL) {
        p = q;
        q = q->dir;
      }
      // Substitui o nó atual pelo maior nó da subárvore esquerda
      if (p != r) {
        p->dir = q->esq;
        q->esq = r->esq;
      }
      q->dir = r->dir;
      free(r);  // Libera a memória do nó atual
      return q; // Retorna o predecessor para ligar ao pai do nó removido
    }
  }
  // Retorna o nó atual (ou o novo nó que substituiu o removido) para o pai do nó atual
  return r;
}

// arvore buscar(arvore r, int k) {
//   if (r == NULL|| r->chave == k)
//     return r;
//   if (r->chave > k)
//     return buscar (r->esq, k);
//   else
//     return buscar (r->dir, k);
// }

void Erd (arvore r) {
  if (r != NULL) {
    Erd(r->esq);
    printf ("%d\n", r->valor);
    Erd(r->dir);
  }
}

int main() {

  arvore raiz = NULL;
  raiz = inserir(raiz, criarNo(10, 100));
  raiz = inserir(raiz, criarNo(5, 50));
  raiz = inserir(raiz, criarNo(20, 200));
  raiz = inserir(raiz, criarNo(3, 30));
  raiz = inserir(raiz, criarNo(7, 70));
  raiz = inserir(raiz, criarNo(15, 150));

  printf("Arvore apos insercoes:\n");
  Erd(raiz);

  // Remover a raiz
  raiz = removerRaiz(raiz);
  printf("\nArvore apos remover a chave 10 (raiz):\n");
  Erd(raiz);

  // Remover um valor específico
  raiz = remover(raiz, 5);
  printf("\nArvore apos remover a chave 5:\n");
  Erd(raiz);

  return 0;
}