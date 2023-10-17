#include <iostream>

using namespace std;

int main(){
        double valorInicialP = 1000;
        double taxadejurosR = 0.14;
        double valorFinalA;
        double tx; //resultado da potência (1+R)^n
        int ano,totalAnos = 10,i;

        for (ano=1; ano <= totalAnos; ano++){
            for (tx=1, i=1; i<=ano; i++){
                tx *= (1+taxadejurosR);        
        }

        valorFinalA = valorInicialP * tx;

        cout << "Valor no ano " << ano << " é " << valorFinalA << endl;
        }

    return 0;
}