#include <iostream>

using namespace std;

int main(){
    float a[4][4]={{1,2,3,4}, {5,6}, {6}};
    for(int j=0; j<4; j++){
        for(int i=0; i<4; i++)
            cout << a[j][i];
        cout << endl;
    }

    return 0;
}