#include <iostream>

using namespace std;

class Forma {

    public: 
        virtual void desenhar() = 0;
        virtual double calcularArea() = 0;
};

class Retangulo : public Forma {
    public:
        float l1, l2;

        Retangulo(float l1, float l2) : l1(l1), l2(l2) {};

        void desenhar(){
            cout << "Desenhando um retangulo" << endl;
        }
        
        double calcularArea () override {
            return l1 * l2; 
        }
};

class Circulo : public Forma {
 
    public:
        const double pi = 3.14;
        float R;
        
        Circulo(float raio) : R(raio) {};

    void desenhar(){
    cout << "Desenhar um circulo" << endl;
    }
            
    double calcularArea (){
    return ((R*R) * pi); 
    }
};

int main (){
    float lado1, lado2, raio;

    cout << "Digite o comprimento do retângulo: " << endl;
    cin >> lado1;

    cout << "Digite a altura do retângulo: " << endl;
    cin >> lado2;

    cout << "Digite o raio do circulo: " << endl;
    cin >> raio;

    Retangulo retangulo(lado1, lado2);
    Circulo circulo(raio);

    cout << "Área do retângulo: " << retangulo.calcularArea() << endl;
    cout << "Área do circulo: " << circulo.calcularArea() << endl;

    return 0;
}