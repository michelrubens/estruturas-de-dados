#include <iostream>

using namespace std;

struct Carro {
    string nome;
    string cor;
    int pot;
    int vMax;
};

int main() {

    Carro car, car2;

    car.nome="Tornado";
    car.cor="Vermelho";
    car.pot=450;
    car.vMax=350;

    car2.nome="Monza";
    car2.cor="Preto";
    car2.pot=250;
    car2.vMax=260;

    cout << "Nome.............: " << car.nome << "\n";
    cout << "Cor..............: " << car.cor << "\n";
    cout << "Potencia.........: " << car.pot << "\n";
    cout << "Velocidade maxima: " << car.vMax << "\n";

    cout << "Nome.............: " << car2.nome << "\n";
    cout << "Cor..............: " << car2.cor << "\n";
    cout << "Potencia.........: " << car2.pot << "\n";
    cout << "Velocidade maxima: " << car2.vMax << "\n";

    return 0;
}