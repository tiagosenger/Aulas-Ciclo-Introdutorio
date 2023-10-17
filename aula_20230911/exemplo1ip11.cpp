#include <iostream>
#include <ctime>

using namespace std;

void maxmin(int vetor[], int n, int &maximo, int &minimo){
    maximo = minimo = vetor [0];
    for (int i=1; i<n; i++){
        if(vetor[i]>maximo) maximo = vetor[i];
        else
        if (vetor[i]<minimo) minimo = vetor[i];
    }
}

void print_vetor(int vetor[], int n){
    for (int i=0; i<n; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int main(){
    int tamanhoVetor = 10;
    int maximo;
    int minimo;
    int vetorTeste[tamanhoVetor] = {0};

    srand(time(nullptr));

    for(int i=0; i<tamanhoVetor; i++) {
        vetorTeste[i] = rand()%43;
    }

    maxmin(vetorTeste,tamanhoVetor,maximo,minimo);

    cout << "Vetor Gerado: ";
    print_vetor(vetorTeste,tamanhoVetor);
    
    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;


    return 0;
}