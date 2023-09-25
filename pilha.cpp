#include <iostream>
#include <stack>

// ----------------
//      PILHAS    
// ----------------

// push: insere elementos
// pop: retira elementos
// size: retorna a quantidade de elementos
// top: retorna a carta do topo
// empty: retorna true se a pilha estiver vazia

using namespace std;

int main() {

    stack <string> cartas;

    cartas.push("Rei de Copas");
    cartas.push("Rei de Espadas");
    cartas.push("Rei de Ouros");
    cartas.push("Rei de Paus");

    cout << "Tamanho da pilha: " << cartas.size() << "\n";

    while(!cartas.empty()) {                                // enquanto cartas NÃO for vazio
        cout << "Carta do topo: " << cartas.top() << "\n";  // mostra a carta de que está no topo
        cartas.pop();                                       // retira os elementos do topo
    }

    return 0;
}