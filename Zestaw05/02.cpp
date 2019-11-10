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

void wypisz(ulamek u) {
    cout << u.l << "/" << u.m << endl;
}

ulamek suma(ulamek a, ulamek b) {
    int nowy_mianownik = nww(a.m, b.m);
    a.l *= nowy_mianownik / a.m;
    b.l *= nowy_mianownik / b.m;
    ulamek wynik;
    wynik.l = a.l + b.l;
    wynik.m = nowy_mianownik;
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

ulamek potega(ulamek u, int w) {
    ulamek wynik = u;
    if (w > 0) {
        for (int i = 1; i < w; i++) {
            wynik = iloczyn(wynik, u);
        }
    }
    else {
        for (int i = 0; i >= w; i--) {
            wynik = iloraz(wynik, u);
        }
    }
    return wynik;
}

enum rodzaj_ukladu {
    oznaczony,
    nieoznaczony,
    sprzeczny
};

//metoda wyznacznikowa
rodzaj_ukladu rozwiaz_uklad(ulamek a, ulamek b, ulamek c, ulamek d, ulamek e, ulamek f, ulamek& x, ulamek& y) {
    ulamek w = roznica(iloczyn(a, e), iloczyn(b, d));
    ulamek wx = roznica(iloczyn(c, e), iloczyn(b, f));
    ulamek wy = roznica(iloczyn(a, f), iloczyn(c, d));
    if (w.l == 0) {
        if (wx.l == 0 && wy.l == 0) {
            return nieoznaczony;
        }
        else {
            return sprzeczny;
        }
    }
    x = iloraz(wx, w);
    y = iloraz(wy, w);
    return oznaczony;
}

int main() {
    try {
        cout << "Podaj wspolczynniki ukladu rownan:" << endl;
        cout << "ax + by = c" << endl;
        cout << "dx + ey = f" << endl;
        ulamek a = wczytaj();
        ulamek b = wczytaj();
        ulamek c = wczytaj();
        ulamek d = wczytaj();
        ulamek e = wczytaj();
        ulamek f = wczytaj();
        ulamek x, y;
        rodzaj_ukladu rodzaj = rozwiaz_uklad(a, b, c, d, e, f, x, y);
        switch (rodzaj) {
            case oznaczony:
                cout << "x = ";
                wypisz(x);
                cout << "y = ";
                wypisz(y);
                break;
            case nieoznaczony:
                cout << "uklad nieoznaczony";
                break;
            case sprzeczny:
                cout << "uklad sprzeczny";
                break;
        }
    }
    catch (const char* e) {
        cout << e;
    }
}