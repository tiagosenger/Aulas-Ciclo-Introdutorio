#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class BancoDeDados {
public:
    static void salvarDados(const string& nomeArquivo, const string& dados) {
        ofstream arquivo_saida(nomeArquivo);

        if (arquivo_saida.is_open()) {
            arquivo_saida << dados;
            arquivo_saida.close();
            cout << "Dados salvos com sucesso!" << endl;
        } else {
            cout << "Erro ao abrir arquivo para escrita." << endl;
        }
    }

    static string RecuperarDados(const string& nomeArquivo) {
        ifstream arquivo_entrada(nomeArquivo);
        string linha;
        string dados;

        if (arquivo_entrada.is_open()) {
            while (getline(arquivo_entrada, linha)) {
                dados += linha + "\n";
            }

            arquivo_entrada.close();
            return dados;
        } else {
            cout << "Erro ao abrir arquivo para leitura." << endl;
            return "";
        }
    }
};

int main() {
    string dadosASalvar = "Escrevendo no arquivo.\n" + to_string(20 + 30) + "\n";
    string nomeArquivo = "teste.txt";

    BancoDeDados::salvarDados(nomeArquivo, dadosASalvar);

    string dadosRecuperados = BancoDeDados::RecuperarDados(nomeArquivo);

    cout << "Dados recuperados: " << endl;
    cout << dadosRecuperados << endl;

    return 0;
}
