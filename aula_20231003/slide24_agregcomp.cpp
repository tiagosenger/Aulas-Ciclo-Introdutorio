#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Evento {
    private: 
        int duracao;
    public:
        Evento(int d) {
            duracao = d;
        }
        int getDuracao(){
            return duracao;
        }
        void setDuracao(int d){
            duracao = d;
        }
};

class Pacote {
    private: 
        string nome;
        vector<Evento> eventos;
    public:
        Pacote (string n) {
            nome = n;
        }
        void adicionaEvento(Evento evento){
            eventos.push_back(evento);
        }
        void listaEventos(){
            cout << "Eventos de " << nome << endl;
            for (Evento e: eventos){
                cout << e.getDuracao() << endl;
            }
        }
};

int main (){
    Pacote p1 ("Pacote 1");
    Pacote p2 ("Pacote 2");
    Evento e1 (1);
    Evento e2 (2);
    Evento e3 (3);
    Evento e4 (4);
    p1.adicionaEvento(e1);
    p1.adicionaEvento(e2);
    p2.adicionaEvento(e2);
    p2.adicionaEvento(e3);
    p1.listaEventos();
    p2.listaEventos();
    e2.setDuracao(10);
    p1.listaEventos();
    p2.listaEventos();
}
