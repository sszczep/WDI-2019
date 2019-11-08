/**
 * Wobec faktu, ze sa to liczby naturalne po prostu szukamy najwiekszej
 * sumy elementow w kolumnie, i najmniejszej sumy elementow w wierszu.
 */
#include <iostream>

using namespace std;

const int MAX = 4;

int main() {
    cout << "uzupelnij tablice liczbami, kolejne liczby trafiaja do tego samego wiersza" << endl;
    int t[MAX][MAX];
    for (int w = 0; w < MAX; w++) {
        cout << "wiersz " << w << endl;
        for (int k = 0; k < MAX; k++) {
            cin >> t[w][k];
        }
    }

    int sumaWiersz[MAX];
    for (int i = 0; i < MAX; i++) {
        sumaWiersz[i] = 0;
    }

    //przy okazji szukania najwiekszej sumy w kolumnie posumujemy sobie wiersze
    int najwKol;
    int najwSumaKol = 0;
    for (int k = 0; k < MAX; k++) {
        int sumaKol = 0;
        for (int w = 0; w < MAX; w++) {
            sumaKol += t[w][k];
            sumaWiersz[w] += t[w][k];
        }
        if (sumaKol > najwSumaKol) {
            najwSumaKol = sumaKol;
            najwKol = k;
        }
    }

    int najmWiersz = 0;
    int najmSumaWiersz = sumaWiersz[0];

    for (int w = 1; w < MAX; w++) {
        if (sumaWiersz[w] < najmSumaWiersz) {
            najmSumaWiersz = sumaWiersz[w];
            najmWiersz = w;
        }
    }

    cout << "kolumna: "  << najwKol << endl;
    cout << "wiersz: " << najmWiersz;
}