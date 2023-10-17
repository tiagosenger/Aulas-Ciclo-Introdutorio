#include <iostream>
#include <string>

using namespace std;

class Mamifero{
    
    private:
        string especie;
        string raca;
        string nomeCientifico;
        string ambiente;
        int tempoGestacao;
    
    public:
    Mamifero(){
        especie = "Indefinido";
        raca = "Indefinido";
        nomeCientifico = "Indefinido";
        ambiente = "Indefinido";
        tempoGestacao = 0;
    }

        void comer(bool fome){
            if(fome){
            cout << "O animal (" << especie << ") está se alimentando..." << endl;
            } else {
                cout << "O animal (" << especie << ") não está com fome" << endl;
            }
        }

        void mamar(bool recemNascido){
            if(recemNascido){
            cout << "O animal (" << especie << ") está mamando..." << endl;
            } else {
            cout << "O animal (" << especie << ") não é um recém nascido" << endl;
            }
        }

    void setEspecie(string _especie){
        especie = _especie;
    }
    string getEspecie(){
        return especie;
    }

    void setRaca(string _raca){
        raca = _raca;
    }
    string getRaca(){
        return raca;
    }

    void setNomeCientifico(string _nomeCientifico){
        nomeCientifico = _nomeCientifico;
    }
    string getNomeCientifico(){
        return nomeCientifico;
    }

    void setAmbiente(string _ambiente){
        ambiente =  _ambiente;
    }
    string getAmbiente(){
        return ambiente;
    }   

    void setTempoGestacao(int _tempoGestacao){
        tempoGestacao = _tempoGestacao;
    }
    int getTempoGestacao(){
        return tempoGestacao;
    }   

    bool operator == (Mamifero _animal){
        return (raca == _animal.raca);
    }

    int operator+ (Mamifero _animal){
        int SomaGestacao = tempoGestacao + _animal.tempoGestacao;
        return SomaGestacao;
    }
};

int main(){

    Mamifero animal1, animal2;
    int SomaGestacao;
    bool flag = false;
    char resposta;
    string strBuff;
    int intBuff;

    cout << "Informe a raça do primeiro animal: " << endl;
    getline (cin >> ws, strBuff);
    animal1.setRaca(strBuff);
   
    cout << "Informe a raça do segundo animal: " << endl;
    getline (cin >> ws, strBuff);
    animal2.setRaca(strBuff);


    cout << "Informe o tempo de gestação em meses do primeiro animal: " << endl;
    cin >> intBuff;
    animal1.setTempoGestacao(intBuff);
   
    cout << "Informe o tempo de gestação em meses do segundo animal: " << endl;
    cin >> intBuff;
    animal2.setTempoGestacao(intBuff);

/*     cout << "O animal é recém nascido?(S/N): " << endl;
    cin >> resposta;
    if (resposta=='S'){
        flag = true;
    }
    animal.mamar(flag);

    cout << "O animal está com fome?(S/N): " << endl;
    cin >> resposta;
    if (resposta=='S'){
        flag = true;
    }
    animal.comer(flag); */

    if (animal1 == animal2){
        cout << "Os animais são iguais" << endl;
    } else {
        cout << "Os animais são diferentes" << endl;
    }
    SomaGestacao = animal1 + animal2;
    cout << "Tempo de gestação total em meses: " << SomaGestacao << endl;
    return 0;
}