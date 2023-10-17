#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*struct passageiro {
    string name;
    string CPF;
    int idade;
};
struct data_hora {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};*/

struct passagem {
    string passageironome;
    string passageirocpf;
    int passageiroidade;

    int assento;
    string tipoviagem;

    int data_dia;
    int data_mes;
    int hora;
    
};

/*int calculototalarrecadado(const passagem &viagem) {
    return viagem.valor * viagem.assento;
};

int main(){

    passagem viagem;
    viagem.valor = 80;
    
    cout << "Quantos assentos foram vendidos na viagem de 8 horas?" << endl;
    cin >> viagem.assento;
    
    int totalarrecadado = calculototalarrecadado(viagem);

    cout << "O total arrecadado foi de R$" << totalarrecadado << ",00" << endl;

    return 0;
} RESOLUÇÃO ERRADA */

int main () {
    vector <passagem> viagens;
    passagem novapassagem;

    bool continuar = true;
    string tempstring;

    while(continuar){
        cout << "Informe o tipo de viagem (ida/volta) ";
        getline (cin, novapassagem.tipoviagem);

        cout << "Informe o mes da viagem ";
        cin >> novapassagem.data_mes;

        cout << "Informe o dia da viagem ";
        cin >> novapassagem.data_dia;

        cout << "Informe a hora da viagem ";
        cout << "(08,10,13,15,20) ";
        cin >> novapassagem.hora;

        cout << "Informe o nome do passageiro ";
        getline(cin >> ws,novapassagem.passageironome);

        cout << "Informe o CPF do passageiro ";
        getline(cin >> ws,novapassagem.passageirocpf);

        cout << "Informe a idade do passageiro ";
        cin >> novapassagem.passageiroidade;

        viagens.push_back(novapassagem);

        cout << "Deseja vender mais uma passagem? (S/N)";
        getline(cin >> ws,tempstring);
        continuar = tempstring == "s" ? true : false;
    }

    for (auto it = viagens.begin();
    it != viagens.end();
    it ++) {   
        cout << (*it).passageironome << endl;
    }

    return 0;
}