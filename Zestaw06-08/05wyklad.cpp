/**
 * Wersja zerznieta z wykladu.
 * Bez smiesznego wyliczania dk, dw. Bo po co :-/
 */
#include <iostream>
using namespace std;

const int N = 5; //domyslnie 8, ale w zyciu sie nie doliczysz
const int POW = N * N;

void wypisz(int t[N][N]) {
    for (int i = 0; i < N; i++) {
        cout << t[i][0];
        for (int j = 1; j < N; j++) {
            cout << ',' << t[i][j];
        }
        cout << endl;
    }
}

bool mozliwe(int t[N][N], int i, int w, int k, int& nw, int& nk) {
    const int dw[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int dk[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    nw = w + dw[i];
    nk = k + dk[i];

    return nw >= 0 && nw < N && nk >= 0 && nk < N && t[nw][nk] == 0;
}

//koniec = false;
//ruch(t, w, k, 1, koniec);
void ruch(int t[N][N], int w, int k, int n, bool& koniec) {
    if (koniec) {
        return;
    }
    t[w][k] = n;
    int nw, nk;
    if (n == POW) {
        koniec = true;
        wypisz(t);
    }
    else {
        for (int i = 0; i < 8; i++) {
            if (mozliwe(t, i, w, k, nw, nk)) {
                ruch(t, nw, nk, n + 1, koniec);
            }
        }
    }
    t[w][k] = 0;
}

int main() {
    int w, k;
    cin >> w >> k;
    int t[N][N];
    bool koniec;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            t[i][j] = 0;
        }
    }
    ruch(t, w, k, 1, koniec);
}