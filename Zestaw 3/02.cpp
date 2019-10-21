#include <iostream>

using namespace std;

int ilosc_cyfr[10] = { 0 };

int a, b;

int main() {
    cin >> a;
    cin >> b;

    int rzad = 10;

    while (a > 0) {
        int cyfra = a % 10;
        ilosc_cyfr[cyfra] = ilosc_cyfr[cyfra] + 1;
        a /= 10;
        rzad *= 10;
    }

    rzad = 1;

    while (b > 0) {
        int cyfra = b % 10;
        ilosc_cyfr[cyfra] = ilosc_cyfr[cyfra] - 1;
        b /= 10;
        rzad *= 10;
    }

    for (int x : ilosc_cyfr) {
        if (x != 0) {
            cout << "nie sa";
            return 0;
        }
    }
    cout << "sa";
}