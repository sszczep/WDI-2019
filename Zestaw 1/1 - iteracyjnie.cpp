#include <iostream>

using namespace std;

int main() {

    //a, b - wyrazy początkowe ciągu (podobnego do) fibonacciego
    int a = 1, b = 1, c;

    while (a < 1000000) {
        cout << a << endl;
        c = a + b;
        a = b;
        b = c;
    }
}