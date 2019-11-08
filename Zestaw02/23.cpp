/**
 * zapis pochodzi z zajęć WDI z 30.10.2019
 */
#include <iostream>

using namespace std;

int a, b;
bool jest_cyfra[16];

int main() {
    int a, b, base;
    cin >> a >> b;

    for (base = 3; base <= 16; base++) {
        for (int i = 0; i < 16; i++) {
            jest_cyfra[i] = false;
        }

        int copyA = a, copyB = b;

        while (copyA > 0) {
            jest_cyfra[copyA % base] = true;
            copyA /= base;
        }
        while (copyB > 0) {
            if (jest_cyfra[copyB % base]) {
                break;
            }
            copyB /= base;
        }

        if (copyB == 0) {
            break;
        }
    }
    if (base == 17) {
        cout << "nie ma takiego systemu";
    }
    else {
        cout << "sa roznocyfrowe w systemie " << base;
    }
}