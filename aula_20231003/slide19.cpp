#include <iostream>

using namespace std;

class ItemBiblioteca {
    
    public:
        string titulo;
        string autor;
        int numCopias;

    ItemBiblioteca(string titulo, string autor, int numCopias):titulo(titulo), autor(autor), numCopias(numCopias) {}

    void exibirDetalhes(){
        cout << "Título: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Numero de cópias disponíveis: " << numCopias << endl;
    }
};

class Livro : public ItemBiblioteca {
    
    public:
       int numPaginas;
    
    Livro(string titulo, string autor, int numCopias, int numPaginas):ItemBiblioteca(titulo, autor, numCopias), numPaginas(numPaginas) {}

    void exibirDetalhes(){
        ItemBiblioteca::exibirDetalhes();
        cout << "Número de páginas: " << numPaginas << endl;
    }
};

class DVD : public ItemBiblioteca {
public:
    int duracaoMinutos;

    DVD(string titulo, string autor, int numCopias, int duracaoMinutos)
        : ItemBiblioteca(titulo, autor, numCopias), duracaoMinutos(duracaoMinutos) {}

    void exibirDetalhes() {
        ItemBiblioteca::exibirDetalhes();
        cout << "Duração (minutos): " << duracaoMinutos << endl;
    }
};

int main() {
    Livro livro("Aventuras de Sherlock Holmes", "Arthur Conan Doyle", 10, 350);
    DVD dvd("Calcinha Preta", "Som Livre", 10, 70);

    cout << "Detalhes do Livro:" << endl;
    livro.exibirDetalhes();

    cout << "\nDetalhes do DVD:" << endl;
    dvd.exibirDetalhes();

    return 0;
}