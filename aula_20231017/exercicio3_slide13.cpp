#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class ListaGenerica {
private:
    vector<T> lista;

public: 
    void adicionarElemento(const T& elemento) {
        lista.push_back(elemento);
    }

    void removerElemento(const T& elemento) {
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (*it == elemento){
                lista.erase(it);
                break;
            }
        }
    }

    void listarElementos() {
        for (const T& elemento : lista){
            cout << elemento << " ";
        }
        cout << endl;
    }
};

int main() {

    ListaGenerica<int> listaInt;
    listaInt.adicionarElemento(10);
    listaInt.adicionarElemento(20);
    listaInt.adicionarElemento(30);

    ListaGenerica<string> listaString;
    listaString.adicionarElemento("Hello");
    listaString.adicionarElemento("World");

    ListaGenerica<double> listaDouble;
    listaDouble.adicionarElemento(3.14);
    listaDouble.adicionarElemento(2.718);

    listaInt.listarElementos();
    listaString.listarElementos();
    listaDouble.listarElementos();

    listaInt.removerElemento(20);
    listaString.removerElemento("Hello");

    listaInt.listarElementos();
    listaString.listarElementos();

    return 0;
}