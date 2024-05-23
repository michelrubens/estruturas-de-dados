// Complexidade: n log2 n --> pior caso n²

#include <stdio.h>

int Separa(int p, int r, int v[]) {
  int c, j, k, t;
  c = v[r]; // Escolhe o pivô como o último elemento do sub-vetor
  j = p - 1; // Inicializa o índice do menor elemento
  // printf("Indice do pivo: %d\n", j + 1);
  for (k = p; k < r; k++) {
    if (v[k] <= c) { // Se o elemento atual é menor ou igual ao pivô
        j++;
        // Troca v[j] com v[k]
        t = v[j];
        v[j] = v[k];
        v[k] = t;
    }
  }
  // Coloca o pivô na posição correta
  t = v[j + 1];
  v[j + 1] = v[r];
  v[r] = t;
  return j + 1; // Retorna o índice do pivô
}

void QuickSort (int p , int r, int v[]) {
  int j;
  if (p < r) {
    j = Separa (p, r, v); // Particiona o vetor e obtém o índice do pivô
    QuickSort (p, j-1, v); // Ordena a parte esquerda do pivô
    QuickSort (j+1, r, v); // Ordena a parte direita do pivô
  }
}

int main() {
    int v[] = { 52, 54, 80, 62, 74, 99, 61, 50, 44, 89, 58 };
    int n = sizeof(v) / sizeof(v[0]);
    
    printf("Array original: \n\t");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    QuickSort(0, n-1, v); // QuickSort(inicio, final, vetor)

    printf("Array ordenado: \n\t");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}