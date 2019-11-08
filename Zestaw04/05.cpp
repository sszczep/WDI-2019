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

    double najwiekszy;
    int najW;
    int najK;
    bool pierwszyIloraz = true;
    for (int w = 0; w < MAX; w++) {
        for (int k = 0; k < MAX; k++) {
            //nie mozemy dzielic przez zero...
            if (sumy_wiersza[w] != 0) {
                double iloraz = (double)sumy_kolumny[k] / sumy_wiersza[w];
                if (iloraz > najwiekszy || pierwszyIloraz) {
                    pierwszyIloraz = false;
                    najwiekszy = iloraz;
                    najW = w;
                    najK = k;
                }
            }
        }
    }

    if (pierwszyIloraz) {
        cout << "suma wszystkich wierszy wynosi 0";
    }
    else {
        cout << "kolumna: "  << najK << endl;
        cout << "wiersz: " << najW;

    }
}
