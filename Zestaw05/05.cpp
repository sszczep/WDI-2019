/**
 * Dla kazdego potencjalnego lewego dolnego rogu kwadratu
 * szukamy najblizszego prawego dolnego rogu i potem pozostale 2,
 * a nastepnie sprawdzamy, czy niczego nie ma w srodku
 */
//TODO: Napisac kod do wprowadzania punktow i testowania funkcji
#include <iostream>

using namespace std;

const int MAX = 100;
const int BOK = 32;

struct punkt {
    int x; //0..31
    int y; //0..31
};

struct dane {
    punkt t[MAX];
    int N;
};

bool istnieja(dane d) {
    bool mapa[BOK][BOK];

    for (int i = 0; i < BOK; i++) {
        for (int j = 0; j < BOK; j++) {
            mapa[i][j] = false;
        }
    }

    //tworzymy sobie mape punktow dla wygody
    for (int i = 0; i < d.N; i++) {
        mapa[d.t[i].x][d.t[i].y] = true;
    }

    //dla kazdego punktu (lewego dolnego rogu)
    nastepny_pkt:
    for (int i = 0; i < d.N; i++) {
        punkt p = d.t[i];
        //potencjalny x prawego dolnego rogu
        int xPD = p.x + 1;
        while (xPD < BOK) {
            //jesli znalezlismy potencjalny prawy dolny rog
            if (mapa[xPD][p.y]) {
                //bok kwadratu
                int dl = xPD - p.x;
                //jezeli potencjalny prawy gorny rog sie miesci na planszy
                if (p.y + dl < BOK) {
                    //jezeli istnieje lewy gorny i prawy gorny rog
                    if (mapa[p.x][p.y + dl] && mapa[xPD][p.y + dl]) {
                        //sprawdzamy, czy nie lezy nic w srodku lewego, gornego i prawego boku
                        for (int j = 1; j < dl; j++) {
                            if (mapa[p.x][p.y + j] || mapa[xPD][p.y + j] || mapa[p.x + j][p.y + dl]) {
                                goto nastepny_pkt;
                            }
                        }
                        //sprawdzamy, czy nie lezy nic wewnatrz kwadratu
                        for (int a = p.x + 1; a < xPD; a++) {
                            for (int b = p.y + 1; b < p.y + dl; b++) {
                                if (mapa[a][b]) {
                                    goto nastepny_pkt;
                                }
                            }
                        }
                        //gitara siema
                        return true;
                    }
                    else {
                        //nie ma gornych rogow, nie ma co szukac dalej prawego dolnego (bo obecny bedzie zawarty w dolnym boku)
                        goto nastepny_pkt;
                    }
                }
                else {
                    //gorny bok sie nie miesci na planszy, cudow nie ma
                    goto nastepny_pkt;
                }
            }
            xPD++;
        }
    }
    return false;
}

int main() {
    
}