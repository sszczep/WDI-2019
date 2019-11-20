#include <iostream>
using namespace std;

int waga(int liczba) {
    if (liczba < 2) {
        return 0;
    }
    int result = 0;
    int dzielnik = 2;
    while (liczba > 1) {
        if (liczba % dzielnik == 0) {
            result++;
            liczba /= dzielnik;
        }
        while (liczba % dzielnik == 0) {
            liczba /= dzielnik;
        }
        dzielnik++;
    }
    return result;
}

//TODO XD
bool da_sie()