#include <iostream>

using namespace std;

class formaGeometrica {
public:
    virtual double area() const = 0;
};

class Circulo: public formaGeometrica {
public:
    double raio;
    Circulo(double r): raio(r){}

    double area() const override {
        return 3.14159 * raio * raio;
    }
};

class Retangulo : public formaGeometrica {
public: 
    double largura, comprimento;
    Retangulo(double l, double c): largura(l), comprimento(c){}

    double area() const override {
        return largura * comprimento;
    }
};

int main() {

    formaGeometrica* formas [2];
    formas[0] = new Circulo(3.0);
    formas [1] = new Retangulo (4.0,5.0);

    for (int i = 0; i < 2; i++){
        cout << "Área da forma" << i+1 << ": " << formas[i]-> area() << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete formas[i];
    }

    return 0; 
}



