// Complexidade: n log2 n

#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int inicio, int meio, int fim) {
  int *vaux = (int *)malloc((fim - inicio + 1) * sizeof(int));

  if (vaux == NULL) {
    printf("Erro ao alocar memoria.\n");
    exit(1);
  }

  for (int i = inicio; i <= fim; i++) {
    vaux[i - inicio] = v[i];
  }

  int i = inicio;
  int j = meio + 1;
  int k = inicio;

  while (i <= meio && j <= fim) {
    if (vaux[i - inicio] < vaux[j - inicio]) {
      v[k] = vaux[i - inicio];
      i++;
    } else {
      v[k] = vaux[j - inicio];
      j++;
    }
    k++;
  }

  while (i <= meio) {
    v[k] = vaux[i - inicio];
    i++;
    k++;
  }

  free(vaux);
}

void mergeSort(int v[], int inicio, int fim) {
  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    mergeSort(v, inicio, meio);
    mergeSort(v, meio + 1, fim);
    merge(v, inicio, meio, fim);
  }
}
int main () {

  // Vetor de teste
  int vet[] = { 52,	54,	80,	62,	74,	99,	61,	50,	64,	89,	58 };
  // Fim do vetor
  int vet_fim = (sizeof(vet) / sizeof(vet[0])) - 1;

  printf("Array inicial: \n");
  for (int i = 0; i <= vet_fim; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");

  // Função mergeSort
  // (vetor, inicio, tamanho)
  mergeSort(vet, 0, vet_fim);

  printf("Array ordenado: \n");
  for (int i = 0; i <= vet_fim; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");

  return 0;
}