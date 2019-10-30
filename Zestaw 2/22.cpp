/**
 * zapis pochodzi z zajęć WDI z 30.10.2019
 */
#include <iostream>

using namespace std;

//zwraca wieksza wartosc z ilosci 2 i 5 w rozkladzie
int ilosc25(int liczba) {
    int i2 = 0, i5 = 0;
    while (liczba % 2 == 0) {
        i2++;
        liczba /= 2;
    }
    while (liczba % 5 == 0) {
        i5++;
        liczba /= 5;
    }
    return max(i2, i5);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << a/b;
    a %= b;

    if (a > 0) {
        cout << '.';
    }

    for (int i = 0; i < ilosc25(b); i++) {
        a *= 10;
        cout << a;
        a %= b;
    }

    if (a > 0) {
        cout << '(';
        int r = a;
        do {
            a *= 10;
            cout << a/b;
            a %= b;
        }
        while (a != r);
        cout << ')';
    }
}