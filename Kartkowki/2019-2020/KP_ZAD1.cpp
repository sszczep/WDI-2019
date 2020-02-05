#include <iostream>
using namespace std;

const int N = 10;
int tab[N][N];

int nwd(int a, int b) {
    return b == 0 ? a : nwd(b, a % b);
}

bool ustawienia() {
    /**
     * dla kazdego mozliwego ustawienia poziomego klocka
     * probujemy dolozyc pionowy i sprawdzamy warunekz NWD
     * 
     * naszymy koordynatami beda lewa czesc klocka poziomego
     * i dolna czesc klocka pionowego
     * 
     * zwroc uwage na sens N - 1 w warunku w petlach
     */
    for (int horX = 0; horX < N - 1; horX++) {
        for (int horY = 0; horY < N; horY++) {
            for (int verX = 0; verX < N; verX++) {
                for (int verY = 0; verY < N - 1; verY++) {
                    //jezeli sie przecinaja to idziemy do nastepnej iteracji
                    if (verX == horX || verX == horX + 1) {
                        if (verY == horY || verY == horY - 1) {
                            continue;
                        }
                    }
                    //nwd(a,b,c,d) == nwd(a, nwd(b, nwd(c, d)))
                    if (nwd(tab[horX][horY],
                        nwd(tab[horX + 1][horY], 
                        nwd(tab[verX][verY],
                        tab[verX][verY + 1]))) == 1) {
                            return true;    
                    }
                }
            }
        }
    }
    return false;
}