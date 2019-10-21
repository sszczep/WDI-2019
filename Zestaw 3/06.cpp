#include <iostream>

using namespace std;

int top10[10] = { 0 };

int main() {
    int input;
    cin >> input;

    while (input != 0) {
        for (int i = 0; i < 10; i++) {
            //jesli wprowadzona liczba jest wieksza niz i-ta liczba w top10...
            if (input >= top10[i]) {
                //...to przesuwamy nastepne elementy top10 o 1 miejsce do tylu...
                for (int j = 9; j > i; j--) {
                    top10[j] = top10[j - 1];
                }
                //...i wstawiamy wprowadzona liczbe w i-te miejsce
                top10[i] = input;
                break;
            }
        }

        //ten kawałek kodu sluzy tylko do wyswietlania zawartosci tablicy z 10 najwiekszymi elementami, zaczyna sie tu:
        cout << endl << endl;
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << " - " << top10[i] << endl;
        }
        cout << endl;
        //i konczy tutaj

        cin >> input;
    }

    cout << endl << "10 co do wielkosci wartosc to: " << top10[9];
}
