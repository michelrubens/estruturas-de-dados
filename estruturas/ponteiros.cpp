#include <iostream>

using namespace std;

main()
{
    string veiculo="Carro";
    string *pv; // armazena o endereço de memória de outra variável

    pv = &veiculo; // ponteiro 'pv' recebe o endereço da variável 'veiculo'

    cout << veiculo << "\n";
    cout << pv << "\n";         // imprime o endereço da variável 'veiculo'
    cout << &veiculo << "\n";   // imprime o endereço da variável 'veículo'

    *pv="Moto"; // No endereço apontado por 'pv' adiciona o valor "Moto"

    cout << veiculo << "\n";    // imprime o valor armazenado na variável 'veiculo'
    cout << *pv << "\n";        // imprime o valor armazenado na variável 'veiculo'

    return 0;
}
