#include <iostream>

using namespace std;

class Desenhavel{
public:
    virtual void desenhar()=0;
};

class Forma{
    
};

class Circulo : public Desenhavel{
public:
    void desenhar() override{
        cout << "Desenhar um circulo." << endl;
    }
};

class Retangulo : public Desenhavel{
public:
    void desenhar() override{
        cout << "Desenhar um retangulo." << endl;
    }
};

class Triangulo : public Desenhavel{
    void desenhar() override{
        cout << "Desenhar um triangulo." << endl;
    }
};

int main(){
    Desenhavel* objetos[3];
    objetos[0]=new Circulo();
    objetos[1]=new Retangulo();
    objetos[2]=new Triangulo();

    for (int i=0; i<3; i++) {
        objetos[i]->desenhar();
    }

    for (int i=0; i<3; i++){
        delete objetos[i];
    }

    return 0;
}