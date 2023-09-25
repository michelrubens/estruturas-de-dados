#include <iostream>
#include <list>

// ----------------
//      LISTAS    
// ----------------

// push_front: insere elementos na frente
// push_back: insere elementos atrás
// front: retorna o elemento da frente
// back: retorna o elemento de trás
// pop_front: retira elementos da frente
// pop_back: retira elementos de trás
// size: retorna a quantidade de elementos
// empty: retorna true se a pilha estiver vazia
// sort: ordena a lista
// reverse: inverte a lista
// insert: insere valor na posição definida (iterador, posição)
// begin: indica primeira posição da lista

using namespace std;

int main() {

    list <int> mesa;
    int qtd;
    list <int> :: iterator it; // iterador

    qtd=10;
    for(int i=0; i<qtd; i++) {
        mesa.push_front(i); // insere no início
    }

    it=mesa.begin(); // indica primeira posição
    advance(it,5); // avança o iterador 5 posições

    mesa.insert(it,0); // insere 0 na posição do iterador

    mesa.sort(); // ordena a lista (de 0 a 9)
    mesa.reverse(); // inverte a lista (de 9 a 0)
    
    cout << "Quantidade de mesas: " << mesa.size() << "\n";

    qtd=mesa.size();
    for(int i=0; i<qtd; i++) {
        cout << mesa.front() << "\n";
        mesa.pop_front();
    }

    return 0;
}