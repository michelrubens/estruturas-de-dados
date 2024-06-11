// Máximo de tempo total: n² unidades de tempo

#include <stdio.h>
#include <stdlib.h>

void imprimeArray(int v[], int n) {
  for (int i = 0; i < n; i++) {
      printf("%d ", v[i]);
  }
  printf("\n");
}

void insercao(int n, int v[]) {
  int i, j, x;
  for (j = 1; /*A*/ j < n; j++) {
    x = v[j];
    for (i = j-1; i >= 0 && v[i] > x; i--) {
      v[i+1] = v[i];
    }
    v[i+1] = x;
  }
}

int main() {
  // Definindo um array de teste
  int v[] = { 10, 7, 6, 11, 12, 3, 2, 1, 8, 9, 13, 14, 5, 4, 15 };
  int n = sizeof(v) / sizeof(v[0]);

  // Imprimindo o array original
  printf("Array original:\n");
  imprimeArray(v, n);

  // Ordenando o array usando o método de inserção
  insercao(n, v);

  // Imprimindo o array ordenado
  printf("Array ordenado:\n");
  imprimeArray(v, n);

  return 0;
}