#include <iostream>
#include <string>


using namespace std;

int main()
{
    string nome;
    cout << "Digite seu nome: ";
    getline(cin,nome);
    cout << endl << "Seu nome é " << nome << endl;
}