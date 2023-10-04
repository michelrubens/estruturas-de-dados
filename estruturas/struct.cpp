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
        cout << "Velocidade maxima: " << vMax << "\n";
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
    Carro car1, car2;

    car1.insere("Tornado", "Vermelho", 450, 350);
    car2.insere("Monza", "Cinza", 250, 260);

    car1.mostra();
    car2.mostra();

    return 0;
}