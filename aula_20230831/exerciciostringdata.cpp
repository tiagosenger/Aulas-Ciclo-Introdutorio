#include <iostream>

using namespace std;

int main(){
    char date [11];

    cout << "Informe a data no formato dd/mm/aaaa: " << endl;
    cin.getline(date,11);

    cout<<date<<endl;
    
        cout << "A data é " << date[0] << date[1] << endl;
        cout << "O mês é " << date[3] << date[4] << endl;
        cout << "o ano é "  << date[6] << date[7] << date[8] << date[9] << endl;
    
    return 0;
}