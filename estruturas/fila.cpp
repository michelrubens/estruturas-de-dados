#include <iostream>
#include <queue>

// ----------------
//      FILAS    
// ----------------

// push: insere elementos
// pop: retira elementos
// size: retorna a quantidade de elementos
// front: primeiro elemento (elemento da frente)
// back: último elemento (elemento de trás)
// empty: retorna true se a fila estiver vazia

using namespace std;

int main() {

    queue <string> cartas;

    cartas.push("Rei de Copas");
    cartas.push("Rei de Espadas");
    cartas.push("Rei de Ouros");
    cartas.push("Rei de Paus");

    cout << "Tamanho da fila: " << cartas.size() << "\n\n";

    while(!cartas.empty()) {                                    // enquanto cartas NÃO for vazio
        cout << "Primeira carta: " << cartas.front() << "\n";   // mostra a carta que está na frente
        cout << "Ultima carta: " << cartas.back() << "\n\n";    // mostra a carta que está atrás
        cartas.pop();                                           // retira os elementos da frente
    }

    return 0;
}