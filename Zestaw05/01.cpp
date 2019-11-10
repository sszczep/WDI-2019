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

int main() {
    ulamek a = wczytaj();
    ulamek b = wczytaj();
    int wykladnik;
    cin >> wykladnik;
    cout << endl;
    wypisz(suma(a, b));
    wypisz(roznica(a, b));
    wypisz(iloczyn(a, b));
    wypisz(iloraz(a, b));
    wypisz(potega(a, wykladnik));
}