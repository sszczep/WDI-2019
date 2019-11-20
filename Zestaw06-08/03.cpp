/**
 * Glowna roznica wzgledem zad 2 polega na tym, ze musimy sprawdzic wszystkie kombinacje
 * ktore sprzyjaja warunkom zadania, a nie wypisac pierwsza, jaka sie nada
 */
#include <iostream>
using namespace std;

const int N = 100;

//odwazniki(t, 0, do_odwazenia, "");
void odwazniki(int t[N], int odwaznik, int do_odwazenia, string kombinacja) {
    //jak wygenerujemy juz cala kombinacje...
    if (odwaznik == N) {
        //...i spelnia ona warunek w zadaniu
        if (do_odwazenia == 0) {
            //coutujemy odwazniki, jakie sie nam przysluzyly
            cout << "zestaw:" << endl;
            for (int i = 0; i < N; i++) {
                if (kombinacja[i] == 'L' || kombinacja[i] == 'P') {
                    //wypisujemy lewa/prawa szalke i odwaznik na szalce
                    cout << kombinacja[i] << t[i] << endl;
                }
            }
        }
    }
    else {
        odwazniki(t, odwaznik + 1, do_odwazenia - t[odwaznik], kombinacja + 'L'); //wrzucamy na lewa szalke
        odwazniki(t, odwaznik + 1, do_odwazenia + t[odwaznik], kombinacja + 'P'); //wrzucamy na prawa szalke
        odwazniki(t, odwaznik + 1, do_odwazenia              , kombinacja + '0'); //a no i na zadna nie wrzucamy xD
    }
}