#include <iostream>

using namespace std;

typedef struct{
    int x;
    int y;
} Point;


int main(){
    Point p1;
    p1.x = 10;
    p1.y = 20;

    Point p2 = {5,15};

    cout << "p1.x: "<< p1.x << ", p1.y: " << p1.y << endl;
    cout << "p2.x: "<< p2.x << ", p2.y: " << p2.y << endl;

    return 0;
}