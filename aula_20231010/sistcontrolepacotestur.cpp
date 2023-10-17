#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Cliente{
    public:
    string nome;
    string cpf;
    string telefone;
    string endereco;
    string DataNascimento;

    Cliente (string _nome, string _cpf, string _telefone, string _endereco, string _DataNascimento){
        nome = _nome;
        cpf = _cpf;
        telefone = _telefone;
        endereco = _endereco;
        DataNascimento = _DataNascimento;
    }
};

class Dependente{
    public: 
    Cliente *dependente_de;
    string nomeDependente;
    string dataNascDependente;
    string cpfDependente;

    Dependente(Cliente* _cliente, string _nomeDependente, string _dataNascDependente, string _cpfDependente){
        dependente_de = _cliente;
        nomeDependente = _nomeDependente;
        dataNascDependente = _dataNascDependente;
        cpfDependente = _cpfDependente;
    }
};

class Evento { // abstrata
    public:
    int duracao;

    Evento(int _duracao){
        duracao = _duracao;
    }

};

class Pacote{
    public:
    string nomePacote;
    vector<Evento*> eventos;

    Pacote(string _nomePacote) : nomePacote (_nomePacote) {}

    void adicionarEvento(Evento *evento){
        eventos.push_back (evento);
    }
};

class Reserva{


};

class Roteiro : public Evento {
    public:
    string atividade;
  
  Roteiro (string _atividade,int _duracao): Evento (duracao){
    atividade =_atividade;
    duracao = _duracao;

  }
                       

};

class Deslocamento : public Evento {
    public:
    string de;
    string para;

    Deslocamento (string _de, string _para, int _duracao): Evento (duracao) {
        de=_de;
        para=_para;
        duracao =_duracao;
    }

};

class Pernoite : public Evento {
    public:
    string local;

    Pernoite (string _local, int _duracao): Evento (duracao){
        local=_local;
        duracao=_duracao;

    }
};


int main(){

    Cliente *cliente1 = new Cliente("Tiago", "060.008", "991111", "Rua São Carlos", "13/04/1996");
        cout << cliente1->nome << endl;
        cout << cliente1->cpf << endl;
    
    Dependente *dependente1 = new Dependente(cliente1, "Iallan", "18/02/1996", "312312312");
        cout << dependente1->nomeDependente << endl;
        cout << dependente1->cpfDependente << endl;

    

    //Cliente cliente1 ("Tiago", "060.008", "991111", "Rua São Carlos", "13/04/1996");


    return 0;
}