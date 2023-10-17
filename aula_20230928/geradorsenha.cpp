#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Senha {
    public: 
        static bool ValidadorSenha (const string& senha) {
            if (senha.length() < 8) {
                return false;
            }
        

            bool temMinuscula = false;
            bool temMaiuscula = false;
            bool temNumero = false;
            bool temCaracterEspecial = false;

            for (char c : senha){
                if (islower(c)){
                    temMinuscula = true;
                } else if (isupper(c)){
                    temMaiuscula = true;
                } else if (isdigit(c)){
                    temNumero = true;
                } else if (ispunct(c)){
                    temCaracterEspecial = true;
                }
            }

        return temMinuscula && temMaiuscula && temNumero && temCaracterEspecial;
    }   

    static string GerarSenhaAleatoria(int tamanho = 12) {
        const string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+=<>?";

        if (tamanho < 8) {
            throw invalid_argument("O tamanho mínimo da senha é 8 caracteres.");
        }

        string senha;
        srand(static_cast<unsigned>(time(nullptr)));

        for (int i = 0; i < tamanho; ++i) {
            int indice = rand() % caracteres.length();
            senha += caracteres[indice];
        }

        return senha;
    }
};

int main() {

    cout << "Bem-vindo ao Gerador de Senhas!" << endl;
    string nomeUsuario;
    
    cout << "Digite seu nome de usuário: ";
    cin >> nomeUsuario;

    while (true) {
        cout << "Gerando uma senha aleatória válida para " << nomeUsuario << ":" << endl;
        string senhaAleatoria = Senha::GerarSenhaAleatoria();
        cout << "Senha gerada: " << senhaAleatoria << endl;

        if (Senha::ValidadorSenha(senhaAleatoria)) {
            cout << "A senha gerada é válida!" << endl;
        } else {
            cout << "Erro: A senha gerada não é válida!" << endl;
        }

        char continuar;
        cout << "Deseja gerar outra senha? (s/n): ";
        cin >> continuar;

        if (continuar != 's' && continuar != 'S') {
            break; 
        }
    }

    cout << "Obrigado por usar o Gerador de Senhas!" << endl;

    return 0;
}