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
// erase: apaga valor na posição definida (posição)
// clear: limpa a lista
// begin: indica primeira posição da lista
// merge: remove elementos de uma lista e junta com os de outra 

using namespace std;

int main() {

    list <int> mesa, teste;
    int qtd;
    list <int> :: iterator it; // iterador

    teste.push_front(9);
    teste.push_front(9);
    teste.push_front(9);
    teste.push_front(9);

    qtd=10;
    for(int i=0; i<qtd; i++) {
        mesa.push_front(i); // insere no início
    }

    it=mesa.begin();
    advance(it,3); // avanca o iterador para a posicao 3
    mesa.insert(it,0); // adiciona 0 na posicao do iterador (3)

    mesa.erase(--it); // remove o 0 inserido anteriormente

    mesa.merge(teste);

    // mesa.sort(); // ordena a lista (de 0 a 9)
    // mesa.reverse(); // inverte a lista (de 9 a 0)

    // mesa.clear(); // limpa a lista 'mesa'
    
    cout << "Quantidade de mesas: " << mesa.size() << "\n\n";

    qtd=mesa.size();
    for(int i=0; i<qtd; i++) {
        cout << mesa.front() << "\n";
        mesa.pop_front();
    }

    cout << "Quantidade de mesas: " << mesa.size() << "\n";

    return 0;
}