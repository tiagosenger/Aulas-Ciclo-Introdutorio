#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estado {
    public:
        string nome;
        string UF;

    Estado(string nome, string UF) : nome(nome), UF(UF) {}
};

class Cidade {
    public:
        string nome;
        Estado *estado;
        
    Cidade(string nome, Estado *estado) : nome(nome), estado(estado) {}
}; 

int main() {
    vector<Estado> estados;
    vector<Cidade> cidades;

    while (true) {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Adicionar Estado" << endl;
        cout << "2. Adicionar Cidade" << endl;
        cout << "3. Listar Estados e Cidades" << endl;
        cout << "4. Sair" << endl;
        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            string nomeEstado, siglaEstado;
            cout << "Digite o nome do estado: ";
            cin >> nomeEstado;
            cout << "Digite a sigla do estado: ";
            cin >> siglaEstado;

            estados.push_back(Estado(nomeEstado, siglaEstado));
            cout << "Estado adicionado com sucesso!" << endl;
        } else if (opcao == 2) {
            string nomeCidade;
            int estadoIndex;

            cout << "Digite o nome da cidade: ";
            cin >> nomeCidade;

            cout << "Escolha o estado para a cidade " << nomeCidade << ":" << endl;
            for (int i = 0; i < estados.size(); ++i) {
                cout << i + 1 << ". " << estados[i].nome << " (" << estados[i].UF << ")" << endl;
            }
            cin >> estadoIndex;
            estadoIndex--;

            if (estadoIndex >= 0 && estadoIndex < estados.size()) {
                cidades.push_back(Cidade(nomeCidade, &estados[estadoIndex]));
                cout << "Cidade adicionada com sucesso!" << endl;
            } else {
                cout << "Índice de estado inválido. A cidade não será cadastrada." << endl;
            }
        } else if (opcao == 3) {
            cout << "\nInformações cadastradas:" << endl;
            cout << "Estados cadastrados:" << endl;
            for (const Estado& estado : estados) {
                cout << estado.nome << " (" << estado.UF << ")" << endl;
            }

            cout << "\nCidades cadastradas:" << endl;
            for (const Cidade& cidade : cidades) {
                cout << cidade.nome << " - Estado: " << cidade.estado->nome << " (" << cidade.estado->UF << ")" << endl;
            }
        } else if (opcao == 4) {
            break;
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}