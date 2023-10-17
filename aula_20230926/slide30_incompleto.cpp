#include <iostream>
#include <string>

using namespace std;

class Carro{
    private: 
        string tipo;
        string cor;
        string placa;
        int numPortas;
    
    public:
        string getTipo() {
            return tipo;
        }

        void setTipo(string_tipo){
            tipo = _tipo;
        }

        string getCor(){
            return cor;
        }

        void setCor (string _cor){
            cor = _cor
        }

        string getPlaca(){
            return placa;
        }

        void setPlaca(string_placa){
            placa = _placa;
        }

        int getNumPortas(){
            return numPortas;
        }

        void setNumPortas(int _numPortas){
            numPortas = _numPortas;
        }
        
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