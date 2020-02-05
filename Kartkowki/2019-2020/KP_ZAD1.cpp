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
     * probujemy dolozyc pionowy i sprawdzamy warunek z NWD
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
                    /**
                     * klocki nie moga lezec w tych samych kolumnach/wierszach
                     * 
                     * warunki kolejno:
                     * pionowy nie moze byc w pionowej linii z lewa polowa poziomego
                     * pionowy nie moze byc w pionowej linii z prawa polowa poziomego
                     * dolna polowa pionowego nie moze byc w poziomej linii z poziomym
                     * gorna polowa pionowego nie moze byc w poziomej linii z poziomym
                     */
                    if (verX == horX || verX == horX + 1 || verY == horY || verY + 1 == horY) {
                        continue;
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