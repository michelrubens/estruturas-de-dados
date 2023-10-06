#include <iostream>

using namespace std;

main()
{
    // string veiculo="Carro";
    // string *pv; // armazena o endereço de memória de outra variável

    // pv = &veiculo; // ponteiro 'pv' recebe o endereço da variável 'veiculo'

    // cout << veiculo << "\n";
    // cout << pv << "\n";         // imprime o endereço da variável 'veiculo'
    // cout << &veiculo << "\n";   // imprime o endereço da variável 'veículo'

    // *pv="Moto"; // No endereço apontado por 'pv' adiciona o valor "Moto"

    // cout << veiculo << "\n";    // imprime o valor armazenado na variável 'veiculo'
    // cout << *pv << "\n";        // imprime o valor armazenado na variável 'veiculo'

    int *p;
    int vetor[10];

    // atribuindo ao ponteiro 'p' o endereço do primeiro elemento do array 'vetor'
    p = vetor; // ou p= &vetor[0];
    *p = 10; // no endereço apontado por 'p', adiciona o valor 10
    cout << "\n" << p << " - ";
    cout << vetor[0] << "\n";

    *(p++);
    *p = 20;
    cout << "\n" << p << " - ";
    cout << vetor[1] << "\n";

    *(p++);
    *p = 30;
    cout << "\n" << p << " - ";
    cout << vetor[2] << "\n";

    return 0;
}
