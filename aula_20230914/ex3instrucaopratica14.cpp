//devdocs.io -> biblioteca

#include <iostream>
#include <cmath>

using namespace std;

struct Ponto {
    int x;
    int y;
};

double calculoDistancia (Ponto &a, Ponto &b) {
    double deltaX = b.x - a.x;
    double deltaY = b.y - a.y;

    return sqrt (deltaX * deltaX + deltaY * deltaY);
    
}

int main () {
    Ponto pontoA, pontoB;
        
    cout << "Digite o valor de x do ponto a: " << endl;
    cin >> pontoA.x;

    cout << "Digite o valor de y do ponto a: " << endl;
    cin >> pontoA.y;

    cout << "Digite o valor de x do ponto b: " << endl;
    cin >> pontoB.x;

    cout << "Digite o valor de y do ponto b: " << endl;
    cin >> pontoB.y;

    double distancia = calculoDistancia (pontoA, pontoB);
    cout << "A distancia entre os pontos é: " << distancia << endl;

    return 0;
}
