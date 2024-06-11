// Complexidade varia com cálculo do GAP

// Fórmula de Donald Knuth:
// Complexidade geramente é O(n^(2/3))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 15

int lista[N] = { 10, 7, 6, 11, 12, 3, 2, 1, 8, 9, 13, 14, 5, 4, 15 };
int trocas = 0;
int comp = 0;
int varred = 0;

void calculaGaps(int *gaps, int *numGaps, int tamanho) {
  float k = (log(tamanho + 1) / log(3)); // k = log3(n + 1)
  k = floor(k + 0.5); // Arredondamento universal

  // Cálculo da distância gap para a primeira varredura
  int gap = (pow(3, k) - 1) / 2;

  *numGaps = 0;
  while (gap > 0) {
    gaps[*numGaps] = gap;
    (*numGaps)++;
    gap = (gap - 1) / 3;
  }
}

void shellSort(int *lista, int tamanho, int *gaps, int numGaps) {
// *lista -> vetor a ser ordenado
// tamanho -> nº de itens do vetor
// *gaps -> array da sequência de gaps
// *numGaps -> nº de gaps calculados, usado para iterar sobre os gaps no shell sort

  int i, j, aux;
  // i -> controle do laço principal
  // j -> controle do laço interno
  // aux -> variável auxiliar para troca de posições

  for (int g = 0; g < numGaps; g++) {
    int gap = gaps[g];

    // Laço principal (de varredura)
    for (i = 0; i < tamanho - gap; i++) {
      comp++;
      if (lista[i] > lista[i + gap]) {
        aux = lista[i + gap];
        lista[i + gap] = lista[i];
        lista[i] = aux;
        j = i - gap;
        trocas++;
        while (j >= 0) {
            comp++;
            if (aux < lista[j]) {
                lista[j + gap] = lista[j];
                lista[j] = aux;
                trocas++;
            } else {
                break;
            }
            j = j - gap;
        }
      }
    }

    printf("\n\nGAP: %d \nVarredura: %d\n", gap, varred); 
    varred++;
  }
}

int main() {

  int w;

  // // Semente para geração de números aleatórios
  // srand(time(NULL));

  // // Preenche vetor com números aleatórios
  // for (int i = 0; i < N; i++) {
  //   lista[i] = rand() % 1000; // Números aleatórios de 0 a 999
  // }

  printf("SHELL SORT\n\n");
  printf("Lista original: ");
  for (w = 0; w < N; w++) {
    printf("%d ", lista[w]);
  }

  int gaps[20]; // Supondo que a sequência de gaps não ultrapassará 20 elementos
  int numGaps;

  calculaGaps(gaps, &numGaps, N);
  shellSort(lista, N, gaps, numGaps);

  printf("\n\nLista ordenada: ");
  for (w = 0; w < N; w++) {
    printf("%d ", lista[w]);
  }
  printf("\n\nComparacoes: %d\nTrocas: %d\nVarreduras: %d\n\n", comp, trocas, varred);

  return 0;
}
