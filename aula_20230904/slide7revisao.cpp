#include <iostream>
#include <string>

using namespace std;

#define N_ELEMENTOS 100
#define N_NOTAS_MAX 20

int main(){

    int elementos [N_ELEMENTOS] = {0};
    int frequencia [N_NOTAS_MAX] = {0};

    srand(time(NULL));

    for (int i=0; i < N_ELEMENTOS; i++){
        elementos[i]=(1 + rand()%N_NOTAS_MAX);
        cout << elementos[i] << endl;
    }

    for (int i = 0; i < N_ELEMENTOS; i++) {
        frequencia[elementos[i] - 1]++; 
    }

        cout << "Frequência de cada número de 1 a " << N_NOTAS_MAX << ":" << endl;
    for (int i = 0; i < N_NOTAS_MAX; i++) {
        cout << "Número " << (i + 1) << ": " << frequencia[i] << " vezes" << endl;
    }

    return 0;
}