#include <iostream>
#include <string>
#include "ClassesTICCarRental.h"

int main() {
    
    Funcionario func1("0000", "Tiago", "Ilhéus", "991148534", "45652478");
    
    Cliente cliTeste = func1.cadastrarCliente("11111", "Iallan", "Rua Almir Bastos", "73 991144444", "3131313131");

    cout << cliTeste.nome << " de telefone: " << cliTeste.telefone << endl;

    return 0;
}
