#include <iostream>

using namespace std;

class Animal{
    protected: 
        string name;
        int age;
    public:
    void fazerSom(){};
};

class Especie : public Animal{
    public: 
        void fazerSom(){
        cout << "Au au!" << endl;
        };
};

int main (){
    Animal animal;
    Especie cachorro;

    cout << "Cachorro faz: " << endl;
    cachorro.fazerSom();
}
