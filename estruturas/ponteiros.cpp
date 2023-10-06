#include <iostream>

using namespace std;

// Prototipação
void somar(float *var, float valor);
void iniciaVetor(float *v);

main()
{
    // ---------- PARTE 1 ----------

    // string veiculo="Carro";
    // string *pv; // armazena o endereço de memória de outra variável

    // pv = &veiculo; // ponteiro 'pv' recebe o endereço da variável 'veiculo'

    // cout << veiculo << "\n";
    // cout << pv << "\n";         // imprime o endereço da variável 'veiculo'
    // cout << &veiculo << "\n";   // imprime o endereço da variável 'veículo'

    // *pv="Moto"; // No endereço apontado por 'pv' adiciona o valor "Moto"

    // cout << veiculo << "\n";    // imprime o valor armazenado na variável 'veiculo'
    // cout << *pv << "\n";        // imprime o valor armazenado na variável 'veiculo'

    // ---------- PARTE 2 ----------

    // int *p;
    // int vetor[10];

    // // atribuindo ao ponteiro 'p' o endereço do primeiro elemento do array 'vetor'
    // p = vetor; // ou p= &vetor[0];
    // *p = 10; // no endereço apontado por 'p', adiciona o valor 10
    // cout << "\n" << p << " - ";
    // cout << vetor[0] << "\n";

    // *(p++);
    // *p = 20;
    // cout << "\n" << p << " - ";
    // cout << vetor[1] << "\n";

    // *(p++);
    // *p = 30;
    // cout << "\n" << p << " - ";
    // cout << vetor[2] << "\n";

    // ---------- PARTE 3 ----------

    float num = 0;
    float vetor[5];

    somar(&num, 15);
    iniciaVetor(vetor);

    cout << num << "\n\n";

    for (int i = 0; i < 5; i++)
    {
        cout << vetor[i] << "\n";
    }

    return 0;
}

// Funções
void somar(float *var, float valor)
{
    *var += valor;
}

void iniciaVetor(float *v)
{
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
}