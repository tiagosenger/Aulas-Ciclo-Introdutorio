#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

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
};

int main() {
    while (true) {
        string senha;

        cout << "Digite a senha: ";
        cin >> senha;

        if (Senha::ValidadorSenha(senha)){
        cout << "Senha valida" << endl;
        } else {
        cout << "Senha inválida, certifique=se de que a senha tenha pelo menos 8 caracteres, contenha letras maiúsculas, letras minúsculas, números e caracteres especiais." << endl;
        }
    }
    
    return 0;
}