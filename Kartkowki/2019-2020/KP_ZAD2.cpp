#include <iostream>
using namespace std;

const int N = 8;
struct klocek {
    int a;
    int b; // b>a
};

klocek zestaw[N];

/**
 * kazdy klocek mozemy wziac, wziac obrocony o 180 stopni lub nie wziac go wcale
 * 
 * mozemy zauwazyc, ze da sie ulozyc ciag z klockow, jezeli
 * a) kazda cyfra wystepuje tyle samo razy na lewej i prawej polowie klocka
 * b) jak wyzej, z wyjatkiem, gdzie jedna cyfra wystepuje o 1 raz rzadziej na lewej
 *    a inna cyfra wystepuje o 1 raz rzadziej na prawej (wtedy to okresla tez poczatek
 *    i koniec naszego ciagu mag-min)
 */

//krotnosci[0][x] - wystepowanie cyfry x na lewej polowie
//krotnosci[1][x] - wystepowanie cyfry x na prawej polowie
void reku(klocek zestaw[N], int krotnosci[2][10], int i, int wziete, int &result) {
    if (i == N) {
        /**
         * te warunki sa nam potrzebne do sprawdzenia, gdyby potencjalne poczatki/konce
         * wystepowaly wiecej niz jeden raz - wtedy z takich klockow ciagu sie ulozyc nie da
         */
        bool nieparzystyPoczatek = false;
        bool nieparzystyKoniec = false;
        for (int j = 0; j < 10; j++) {
            int roznica = krotnosci[0][j] - krotnosci[1][j];
            if (roznica == 1) {
                if (!nieparzystyPoczatek) {
                    nieparzystyPoczatek = true;
                }
                else {
                    return;
                }
            }
            else if (roznica == -1) {
                if (!nieparzystyKoniec) {
                    nieparzystyKoniec = true;
                }
                else {
                    return;
                }
            }
            //nie da sie ulozyc ciagu rowniez wtedy, gdy roznica w wystepowaniu na lewej/prawej polowie jest >= 2
            //dziala bo wylaczylismy wczesniej wypadek roznicy -1 i 1
            else if (roznica != 0) {
                return;
            }
        }
        if (wziete > result) {
            result = wziete;
        }
    }
    else {
        //bierzemy klocek normalnie
        krotnosci[0][zestaw[i].a]++;
        krotnosci[1][zestaw[i].b]++;
        reku(zestaw, krotnosci, i + 1, wziete + 1, result);
        krotnosci[0][zestaw[i].a]--;
        krotnosci[1][zestaw[i].b]--;
        
        //bierzemy klocek obrocony o 180 stopni
        krotnosci[0][zestaw[i].b]++;
        krotnosci[1][zestaw[i].a]++;
        reku(zestaw, krotnosci, i + 1, wziete + 1, result);
        krotnosci[0][zestaw[i].b]--;
        krotnosci[1][zestaw[i].a]--;

        //nie bierzemy klocka wcale
        reku(zestaw, krotnosci, i + 1, wziete    , result);
    }
}

//funkcja okalajaca
int maxZestaw(klocek zestaw[N]) {
    int krotnosci[2][10];
    for (int i = 0; i < 10; i++) {
        krotnosci[0][i] = 0;
        krotnosci[1][i] = 0;
    }
    int result = 0;
    reku(zestaw, krotnosci, 0, 0, result);
    return result;
}

int main() {
    zestaw[0].a = 2;
    zestaw[0].b = 8;

    zestaw[1].a = 0;
    zestaw[1].b = 1;

    zestaw[2].a = 2;
    zestaw[2].b = 3;

    zestaw[3].a = 3;
    zestaw[3].b = 6;

    zestaw[4].a = 2;
    zestaw[4].b = 6;

    zestaw[5].a = 2;
    zestaw[5].b = 9;

    zestaw[6].a = 3;
    zestaw[6].b = 4;

    zestaw[7].a = 6;
    zestaw[7].b = 7;

    cout << maxZestaw(zestaw);
}