#include <iostream>

using namespace std;

class Calculadora {
    public:
    
    static double adicao(double a, double b){
        return a + b;
    }

    static double subtracao(double a, double b){
        return a - b;
    }

    static double multiplicacao(double a, double b){
        return a * b;
    }

    static double divisao(double a, double b){
        if (b == 0) {
            cout << "Erro: Divisão por zero!" << endl;
            return 0.0;
        }
        return a / b;
    }
};

class InterfaceUsuario {
    public:
        static void executar(){
         double num1, num2;
        char operacao;

        cout << "Digite o primeiro número: ";
        cin >> num1;

        cout << "Digite a operação (+, -, *, /): ";
        cin >> operacao;

        cout << "Digite o segundo número: ";
        cin >> num2;

        bool sucesso = true;
        double resultado;

        switch (operacao) {
        case '+':
            resultado = Calculadora::adicao(num1, num2);
            break;
        case '-':
            resultado = Calculadora::subtracao(num1, num2);
            break;
        case '*':
            resultado = Calculadora::multiplicacao(num1, num2);
            break;
        case '/':
            resultado = Calculadora::divisao(num1, num2);
            break;
        default:
            sucesso = false;
        }

        if (sucesso) {
            cout << "Resultado: " << resultado << endl;
        } else {
            cout << "Erro: operação inválida ou divisão por zero!" << endl;
        }
    }
};

int main() {
    InterfaceUsuario::executar();
    return 0;
}