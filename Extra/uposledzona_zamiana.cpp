/**
 * Zamiana liczby base 10 na base 2 bez akumulowania jej w tablicy/stringu
 */
#include <iostream>
using namespace std;

int main() {
    int do_zamiany;
    cin >> do_zamiany;
    int potega_2 = 1;
    while (potega_2 <= do_zamiany) {
        potega_2 *= 2;
    }
    potega_2 /= 2;
    while (potega_2 > 0) {
        if (do_zamiany >= potega_2) {
            do_zamiany -= potega_2;
            cout << '1';
        }
        else {
            cout << '0';
        }
        potega_2 /= 2;
    }
}