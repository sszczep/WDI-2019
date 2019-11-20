/**
 * Nie jest to do końca po prostu algorytm z zad. 2, bo sprawdzamy
 * tylko jedna szalke.
 * W tym algorytmie brakuje zamiany ciagu zer/jedynek na wlasciwe odwazniki
 * ale wg profesora to zadanie dla przedszkolakow xD to nie zapisalismy
 */
#include <iostream>
using namespace std;

const int N = 100;

//waga(t,23,0,"")
void waga(int t[N], int m, int p, string res) {
    if (p == N) {
        if (m == 0) {
            //tu zamiast wypisac res powinnismy zamienic ciag 0 i 1 na elementy t[i];
            cout << res;
        }
    }
    else {
        waga(t, m - t[p], p + 1, res + '1');
        waga(t, m, p + 1, res + '0');
    }
}