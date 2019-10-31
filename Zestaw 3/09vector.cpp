#include <iostream>
#include <vector>

using namespace std;

void wypisz_zawartosc(vector<int> &t, bool* dost) {
    for (int i = 0; i < t.size(); i++) {
        cout << '|' << t[i];
    }
    cout << '|' << endl;

    for (int i = 0; i < t.size(); i++) {
        int liczba_cyfr = 0;
        int copy = t[i];
        while (copy > 0) {
            liczba_cyfr++;
            copy /= 10;
        }
        char fill_char = dost[i] ? '+' : '-';
        cout << '|';
        for (int j = 0; j < liczba_cyfr; j++) {
            cout << fill_char;
        }
    }
    cout << '|' << endl;
}

void skoki(vector<int> &t) {
    bool* dost = new bool[t.size()];
    dost[0] = true;

    for (int i = 1; i < t.size(); i++) {
        dost[i] = false;
    }

    for (int i = 0; i < t.size() - 1; i++) {
        if (dost[i]) {
            int copy = t[i];
            int podzielnik = 2;
            while (copy > 1) {
                if (copy % podzielnik == 0) {
                    if (i + podzielnik < t.size()) {
                        dost[i + podzielnik] = true;
                    }
                    if (i + podzielnik == t.size() - 1) {
                        wypisz_zawartosc(t, dost);
                        cout << "przejscie do pola n-1 jest mozliwe" << endl;
                        return;
                        //return true;
                    }
                    while (copy % podzielnik == 0) {
                        copy /= podzielnik;
                    }
                }
                podzielnik++;
            }
        }
    }

    wypisz_zawartosc(t, dost);
    cout << "przejscie do pola n-1 NIE jest mozliwe" << endl;
    //return false;
}

int main() {
    while (true) {
        int nastepna;
        vector<int> ciag_naturalnych;

        cout << "podaj ciag liczb naturalnych i zakoncz jego wprowadzanie wpisujac 0 (lub zakoncz program ctrl+c)" << endl;
        cin >> nastepna;

        while (nastepna != 0) {
            if (nastepna > 0) {
                ciag_naturalnych.push_back(nastepna);
            }
            else {
                cout << "liczba ujemna nie jest naturalna" << endl;
            }
            cin >> nastepna;
        }
        cout << endl;
        if (ciag_naturalnych.size() < 2) {
            cout << "wprowadz co najmniej 2 liczby" << endl;
        }
        else {
            skoki(ciag_naturalnych);
        }
        cout << endl;
    }
}