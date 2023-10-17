#include <iostream>
#include <string>

using namespace std;

class Carro{
    public: 
        string tipo;
        string cor;
        string placa;
        int numPortas;

        void acelerar(float _velocidade){
            cout << "acelerando para " << _velocidade << "km/h" << endl;
        }

        void frear (){
            cout << "freando" << endl;
        }
};

int main(void){
    Carro civic;
    civic.tipo = "Sedan";
    cout << civic.tipo << endl;

    civic.acelerar(30);
    civic.frear();
}