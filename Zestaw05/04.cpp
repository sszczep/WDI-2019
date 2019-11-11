/**
 * Zasada dzialania jest taka, ze program szuka najdluzszych spojnych ciagow
 * arytmetycznych i geometrycznych, a jak dojdziemy do konca takiego ciagu,
 * to program dodatkowo liczy ile ten ciag ma podciagow o dl >= 3
 */
#include <iostream>

using namespace std;

struct ulamek {
    int l;
    int m;
};

int nwd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return (a > 0) ? a : a * -1;
}

int nww(int a, int b) {
    return a * b / nwd(a, b);
}

ulamek skroc(ulamek u) {
    if (u.l == 0) {
        u.m = 1;
        return u;
    }
    int podziel = nwd(u.l, u.m);
    u.l /= podziel;
    u.m /= podziel;
    return u;
}

ulamek wczytaj() {
    ulamek wynik;
    cin >> wynik.l;
    cin >> wynik.m;
    if (wynik.m == 0) {
        throw "mianownik nie moze wynosic 0";
    }
    if (wynik.m < 0) {
        wynik.l *= -1;
        wynik.m *= -1;
    }
    return skroc(wynik);
}

ulamek roznica(ulamek a, ulamek b) {
    int nowy_mianownik = nww(a.m, b.m);
    a.l *= nowy_mianownik / a.m;
    b.l *= nowy_mianownik / b.m;
    ulamek wynik;
    wynik.l = a.l - b.l;
    wynik.m = nowy_mianownik;
    return skroc(wynik);
}

ulamek iloczyn(ulamek a, ulamek b) {
    ulamek wynik;
    wynik.l = a.l * b.l;
    wynik.m = a.m * b.m;
    return skroc(wynik);
}

ulamek iloraz(ulamek a, ulamek b) {
    if (b.l == 0) {
        throw "nie mozna dzielic przez 0";
    }
    ulamek dzielnik;
    dzielnik.l = b.m;
    dzielnik.m = b.l;
    if (dzielnik.m < 0) {
        dzielnik.l *= -1;
        dzielnik.m *= -1;
    }
    return iloczyn(a, dzielnik);
}

bool rowne(ulamek a, ulamek b) {
    a = skroc(a);
    b = skroc(b);
    return a.l == b.l && a.m == b.m;
}
//tu sie zaczyna wlasciwe zadanie

const int MAX = 100;
const ulamek ZERO = {0, 1};

//ile jest spojnych podciagow o dl >= 3 w ciagu n liczb?
int podciagi(int n) {
    return (n-1)*(n-2)/2;
}

int ciagi(ulamek t[MAX]) {
    int LA = 0;
    int LG = 0;
    
    //ciag arytmetyczny
    int i = 0;
    while (i < MAX - 2) {
        if (rowne(roznica(t[i+2], t[i+1]), roznica(t[i+1], t[i]))) {
            ulamek r = roznica(t[i+2], t[i+1]);
            int dl = 3;
            while (i + 3 <= MAX - 1 && rowne(roznica(t[i+3], t[i+2]), r)) {
                i++;
                dl++;
            }
            LA += podciagi(dl);
            i = i + 2;
        }
        else {
            i++;
        }
    }

    //ciag geometryczny
    i = 0;
    while (i < MAX - 2) {
        /**
         * tu sie wszystko zaczyna pierdolic, bo szczegolnym przypadkiem
         * ciagu geometrycznego jest ciag x,0,0 w ktorym nie mozemy wyznaczyc
         * q na podstawie ilorazu kolejnych wyrazow, wiec trzeba go obsluzyc
         * oddzielnie sprawdzajac inne warunki...
         * 
         * drugim problemem jest dzielenie przez 0, tez to trzeba wylaczyc
         */

        //najpierw sprawdzamy ciag typu x,0,0,0,0....
        if (rowne(t[i+2], ZERO) && rowne(t[i+1], ZERO)) {
            int dl = 3;
            while (i + 3 <= MAX - 1 && rowne(t[i+3], ZERO)) {
                i++;
                dl++;
            }
            LG += podciagi(dl);
            i = i + 2;
        }
        else if (rowne(t[i+1], ZERO) || rowne(t[i], ZERO)) {
            /**
             * nie mozemy dopuscic do sytuacji, ze elementy i, i+1 beda
             * rowne 0, bo wtedy podzielimy przez 0 w nastepnych warunkach
             * 
             * skoro wylapalismy ciag zaczynajacy sie od x,0,0 wczesniej, to
             * ten warunek nie wykluczy ciagu geom. o q = 0, wiec po prostu
             * pomijamy ten przypadek
             */
            i++;
        }
        else if (rowne(iloraz(t[i+2], t[i+1]), iloraz(t[i+1], t[i]))) {
            ulamek q = iloraz(t[i+2], t[i+1]);
            int dl = 3;
            while (i + 3 <= MAX - 1 && rowne(iloraz(t[i+3], t[i+2]), q)) {
                i++;
                dl++;
            }
            LG += podciagi(dl);
            i = i + 2;
        }
        else {
            i++;
        }
    }
    return LA > LG ? 1 : (LA == LG ? 0 : -1);
}

int main() {
    ulamek t[MAX];
    for (int i = 0; i < MAX; i++) {
        t[i] = wczytaj();
    }
    cout << ciagi(t);
}