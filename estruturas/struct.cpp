#include <iostream>

using namespace std;

struct Carro
{
    string nome;
    string cor;
    int pot;
    int vMax;
    int vel;

    // Métodos
    void insere(string stnome, string stcor, int stpot, int stvMax)
    {
        nome = stnome;
        cor = stcor;
        pot = stpot;
        vMax = stvMax;
        vel=0;
    }

    void mostra()
    {
        cout << "Nome.............: " << nome << "\n";
        cout << "Cor..............: " << cor << "\n";
        cout << "Potencia.........: " << pot << "\n";
        cout << "Velocidade atual.: " << vel << "\n";
        cout << "Velocidade maxima: " << vMax << "\n\n";
    }

    void mudaVel(int mv)
    {
        vel=mv;
        if (vel > vMax)
        {
            vel=vMax;
        }
        if (vel < 0)
        {
            vel=0;
        }
    }
};

int main()
{
    Carro *carros = new Carro[5]; // array será um ponteiro
    // Carro car1, car2, car3, car4, car5;

    // carros[0] = car1;
    // carros[1] = car2;
    // carros[2] = car3;
    // carros[3] = car4;
    // carros[4] = car5;

    carros[0].insere("Tornado", "Vermelho", 350, 450);
    carros[1].insere("Monza", "Cinza", 250, 260);
    carros[2].insere("Corsa", "Prata", 150, 200);
    carros[3].insere("Gol", "Amarelo", 200, 260);
    carros[4].insere("Fusca", "Azul", 180, 200);

    for(int i=0; i<5; i++)
    {
        carros[i].mostra();
    }

    return 0;
}