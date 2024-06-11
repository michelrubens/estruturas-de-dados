// Máximo de tempo total: n² unidades de tempo

#include <stdio.h>
#include <stdlib.h>

void imprimeArray(int v[], int n) {
  for (int i = 0; i < n; i++) {
      printf("%d ", v[i]);
  }
  printf("\n");
}

void selecao (int n, int v[]) {
  int i, j, min, x;
  for (i = 0; /* A */ i < n-1; i++) {
    min = i;
    for (j = i+1; j < n; j++) 
      if (v[j] < v[min]) min = j;
    x = v[i];
    v[i] = v[min];
    v[min] = x;
  } 
}

int main() {
  // Definindo um array de teste
  int v[] = { 74, 12, 15, 32, 74, 89, 53, 27, 5, 91, 68, 42, 10, 78, 19 };
  int n = sizeof(v) / sizeof(v[0]);

  // Imprimindo o array original
  printf("Array original:\n");
  imprimeArray(v, n);

  // Ordenando o array usando o método de inserção
  selecao(n, v);

  // Imprimindo o array ordenado
  printf("Array ordenado:\n");
  imprimeArray(v, n);

  return 0;
}