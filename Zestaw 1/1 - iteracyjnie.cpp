#include <iostream>

using namespace std;

int main() {
    /*
    int szukana_liczba;
    cin >> szukana_liczba;
    */
    int a = 0, b = 1, c = 1;

    while (c < 1000000) {
        cout << c << endl;
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}