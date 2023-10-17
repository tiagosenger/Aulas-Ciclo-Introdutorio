#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nome1 = "Joaquim";
    string nome2 = "Nabuco";
    cout << nome1 << endl;
    cout << nome2 << endl;
    nome1.swap(nome2);
    cout << nome1 << endl;
    cout << nome2 << endl;
}