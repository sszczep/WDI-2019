/**
 * sprawdzanie moznaby ominac, gdyby komus sie udalo ustalic
 * od jakiego N (zakladajac, ze kazdy hetman opisuje innego)
 * z zasady pudelkowania Dirichleta na pewno sa 2 w jednej linii
 * 
 * jak ktos to ogarnie to jest k0z4k
 */
#include <iostream>
using namespace std;

const int BOK = 100;

struct hetman {
    int w;
    int k;
};

struct dane {
    hetman t[100];
    int N;
};

bool szachuja_sie(dane dane) {
    //jest tylko 1 hetman wiec jak maja sie szachowac
    if (dane.N == 1) {
        return false;
    }
    //informacje o kazdym hetmanie przenosimy na plansze typu bool (prawda -> jest tam hetman)
    bool plansza[BOK][BOK];
    for (int w = 0; w < BOK; w++) {
        for (int k = 0; k < BOK; k++) {
            plansza[w][k] = false;
        }
    }
    for (int i = 0; i < dane.N; i++) {
        hetman h = dane.t[i];
        plansza[h.w][h.k] = true;
    }
    //a teraz sprawdzamy, czy nie ma 2 hetmanow na kazdej z linii pionowych, poziomych i ukosnych:
    //poziome i pionowe
    for (int i = 0; i < BOK; i++) {
        //czy znalezlismy juz jednego?
        bool jest_pio = false;
        bool jest_poz = false;
        for (int j = 0; j < BOK; j++) {
            if (plansza[i][j]) {
                if (jest_pio) {
                    return true;
                }
                jest_pio = true;
            }
            if (plansza[j][i]) {
                if (jest_poz) {
                    return true;
                }
                jest_poz = true;
            }
        }
    }
    /**
     * w ukosnych zasada polega na tym, ze zaczynamy od pkt [1, 0]..[BOK - 1, 0]..[BOK - 1, BOK - 2]
     * i od kazdego pkt startowego lecimy o 1 kratke w gore i prawo az do krawedzi
     * i jednoczesnie ta sama operacje wykonujemy dla odbicia lustrzanego
     * 
     * w ten sposob sprawdzamy wszystkie linie ukosne o dl co najmniej 2
     */

    //najpierw przesuwamy sie z punktem poczatkowym w dol, potem w prawo
    bool pocz_w_bok = false;
    int poczW = 1;
    int poczK = 0;
    while (!(poczW == BOK - 1 && poczK == BOK - 1)) {
        int w = poczW;
        int k = poczK;
        //czy znalezlismy juz jednego?
        bool jest_u1 = false;
        bool jest_u2 = false;
        while (w >= 0 && k <= BOK - 1) {
            if (plansza[w][k]) {
                if (jest_u1) {
                    return true;
                }
                jest_u1 = true;
            }
            //odbicie lustrzane wzgledem kolumn
            if (plansza[w][BOK - 1 - k]) {
                if (jest_u2) {
                    return true;
                }
                jest_u2 = true;
            }
            //o 1 w gore i prawo
            w--;
            k++;
        }
        //jesli dotarlismy do rogu, przesuwamy sie w prawo zamiast w dol
        if (poczW == BOK - 1) {
            pocz_w_bok = true;
        }
        if (pocz_w_bok) {
            poczK++;
        }
        else {
            poczW++;
        }
    }
    return false;
}

int main() {
    int N;
    cout << "wprowadz ilosc hetmanow <= 100" << endl;
    cin >> N;
    dane d;
    d.N = N;
    for (int i = 0; i < N; i++) {
        cout << "wpisz w,k hetmana " << i << endl;
        hetman h;
        cin >> h.w;
        cin >> h.k;
        d.t[i] = h;
    }
    cout << (szachuja_sie(d) ? "tak" : "nie");
}