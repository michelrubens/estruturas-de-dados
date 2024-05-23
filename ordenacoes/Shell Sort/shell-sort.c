// Complexidade varia com cálculo do GAP

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 15
// int lista[N];
int lista[N] = { 10, 7, 6, 11, 12, 3, 2, 1, 8, 9, 13, 14, 5, 4, 15 };
int trocas = 0;
int comp = 0;
int varred = 0;

void shellSort(int *lista, int tamanho) {
// *lista -> vetor a ser ordenado
// tamanho -> nº de itens do vetor

  int i, j, aux;
  // i -> controle do laço principal
  // j -> controle do laço interno
  // aux -> variável auxiliar para troca de posições 

  float k = (log(tamanho + 1) / log(3)); // k = log3(n + 1)
  k = floor(k + 0.5); // Arredondamento universal

  // Cálculo da distância gap para a primeira varredura
  int gap = (pow(3, k) - 1) / 2;

  // Laço principal (de varredura)
  while (gap > 0) {
    // Laço interno (de avanço)
    for (i = 0; i < tamanho - gap; i++) {
      // i -> índice do elemento a ser comparado
      comp++;
      // Estrutura condicional
      if (lista[i] > lista[i + gap]) {
        // Troca de posições
        aux = lista[i + gap];
        lista[i + gap] = lista[i];
        lista[i] = aux;
        j = i - gap;
        trocas++;
        // Laço interno (de deslocamento)
        while (j >= 0) {
          comp++;
          if (aux < lista[j]) {
            lista[j + gap] = lista[j];
            lista[j] = aux;
            trocas++;
          } else { break; }
          j = j - gap;
        }
      }
    } 
    // Atualiza o 'gap' conforme a fórmula de Donald Ervin Knuth
    printf("\n\nGAP: %d \nVarredura: %d\n", gap, varred); 
    gap = (gap - 1) / 3;
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

  shellSort(lista, N);

  printf("\n\nLista ordenada: ");
  for (w = 0; w < N; w++) {
    printf("%d ", lista[w]);
  }
  printf("\n\nComparacoes: %d\n\nTrocas: %d\n\nVarreduras: %d\n\n", comp, trocas, varred);

  return 0;
}
