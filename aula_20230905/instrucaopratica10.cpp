#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    int qtdalunos;
    cout << "Digite a quantidade de alunos: " << endl;  
    cin >> qtdalunos;
   
    vector<string> nomes = {};
    vector<float> nota1, nota2;

    cin.ignore();
    
    for (int i=0; i < qtdalunos; i++){
        string nomedoaluno;
        float n1, n2;

        cout << "Digite o nome do aluno: " << endl;
        getline (cin, nomedoaluno);
        nomes.push_back(nomedoaluno);
        
        cout << "Digite a nota 1 do aluno " << nomedoaluno << ":" << endl;
        cin >> n1;
        nota1.push_back(n1);
        
        cout << "Digite a nota 2 do aluno " << nomedoaluno << ":" << endl;
        cin >> n2;
        nota2.push_back(n2);

        cin.ignore();

    }

    //cout << nomes.end();
      
    return 0;
}