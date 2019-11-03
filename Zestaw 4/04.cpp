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

    int sumy_wiersza[MAX];
    int sumy_kolumny[MAX];

    for (int i = 0; i < MAX; i++) {
        sumy_wiersza[i] = 0;
        sumy_kolumny[i] = 0;
    }

    for (int w = 0; w < MAX; w++) {
        for (int k = 0; k < MAX; k++) {
            sumy_wiersza[w] += t[w][k];
            sumy_kolumny[k] += t[w][k];
        }
    }

    double najwiekszy = 0.0;
    int najW;
    int najK;
    for (int w = 0; w < MAX; w++) {
        for (int k = 0; k < MAX; k++) {
            double iloraz = (double)sumy_kolumny[k] / sumy_wiersza[w];
            if (iloraz > najwiekszy) {
                najwiekszy = iloraz;
                najW = w;
                najK = k;
            }
        }
    }

    cout << "kolumna: "  << najK << endl;
    cout << "wiersz: " << najW;
}