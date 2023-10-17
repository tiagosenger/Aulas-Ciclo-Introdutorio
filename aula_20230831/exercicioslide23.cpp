#include <iostream>
using namespace std;

int main(){
    int nota;
    double mediaNotas = 0.0;
    char continuar;
    int totalAlunos = 0;
    int somaNotas = 0;

    do{
        do{
            totalAlunos++;
            cout << "Digite a nota do aluno " << totalAlunos << endl;
            cin >> nota;
            if(nota >= 0 && nota <= 100){
                somaNotas += nota;
                mediaNotas = somaNotas / totalAlunos;
            }else{
                cout << "Nota inválida" << endl;
            }
        }
        while(nota < 0 || nota >100); // "||" significa "ou"
 
        cout << "Deseja continuar? [S/N]" << endl;
        cin >> continuar;
    }while(continuar != 'n' && continuar != 'N');

    cout << "Média das notas: " << mediaNotas << endl;

    mediaNotas = somaNotas / totalAlunos;

    cout << "A quantidade de alunos foi: " << totalAlunos << endl;
    cout << "A média da turma foi: " << mediaNotas << endl;

    return 0;
  
}
