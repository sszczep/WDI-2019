#include <iostream>
using namespace std;

struct klocek {
    int a;
    int b;
    klocek *next;
};

void reorder(klocek *&klocki) {
    int p[10];
    int k[10];
    int doWstawienia = 0;

    for (int i = 0; i < 10; i++) {
        p[i] = 0;
        k[i] = 0;
    }

    klocek *zliczanie = klocki;

    /**
     * okazuje sie, ze jesli policzymy ile jest poczatkow/koncow
     * dla kazdej cyfry, to mozemy wyznaczyc poczatek i koniec
     * ciagu mag-mino. dla wszystkich innych cyfr niz poczatek/koniec
     * liczba wystapien bedzie rowna. analogicznie do zad 2
     * 
     * moze byc tez tak, ze liczba wystapien wszystkich liczb
     * na lewej i prawej polowie jest rowna, wtedy poczatek jest dowolny
     */
    while (zliczanie != nullptr) {
        p[zliczanie->a]++;
        k[zliczanie->b]++;
        zliczanie = zliczanie->next;
        doWstawienia++;
    }
    doWstawienia--;

    if (doWstawienia <= 0) {
        return;
    }

    int poczatek = -1;
    int koniec = -1;
    for (int i = 0; i < 10; i++) {
        if (p[i] > k[i]) {
            poczatek = i;
        }
        if (p[i] < k[i]) {
            koniec = i;
        }
    }
    //przypadek, gdy poczatek/koniec wybieramy dowolnie
    if (poczatek == -1) {
        for (int i = 0; i < 10; i++) {
            if (p[i] > 0) {
                poczatek = i;
                continue;
            }
            if (k[i] > 0) {
                koniec = i;
                continue;
            }
        }
    }

    klocek *przestawione = nullptr;
    klocek *przestawioneLast = nullptr;
    while (doWstawienia > 0) {
        klocek *tmp = klocki;
        klocek *tmpPrev = nullptr;
        while (tmp != nullptr) {
            /**
             * nie mozemy dokleic przypadkiem klocka z koncem, bo za wczesnie skonczymy ciag
             * (nie tyczy sie to ostatniego klocka, dokleimy go poza petla)
             * klocek ktory bedziemy doklejac bedziemy wybierac na podstawie konca poprzednio
             * doklejonego
             */
            if (tmp->a == poczatek && tmp->b != koniec) {
                if (tmpPrev == nullptr) {
                    klocki = tmp->next;
                }
                else {
                    tmpPrev->next = tmp->next;
                }
                if (przestawione == nullptr) {
                    przestawione = tmp;
                }
                else {
                    przestawioneLast->next = tmp;
                }
                przestawioneLast = tmp;
                przestawioneLast->next = nullptr;
                doWstawienia--;
                poczatek = tmp->b;
                break;
            }
            tmpPrev = tmp;
            tmp = tmp->next;
        }
    }
    przestawioneLast->next = klocki;
    klocki = przestawione;
}

void wypisz(klocek *klocki) {
    while (klocki != nullptr) {
        cout << klocki->a << '|' << klocki->b << ' ';
        klocki = klocki->next;
    }
    cout << endl;
}

int main() {
    klocek *klocki = nullptr;
    klocek *tmp;

    tmp = new klocek;
    tmp->a = 6;
    tmp->b = 2;
    tmp->next = klocki;
    klocki = tmp;
    
    tmp = new klocek;
    tmp->a = 2;
    tmp->b = 3;
    tmp->next = klocki;
    klocki = tmp;
    
    tmp = new klocek;
    tmp->a = 8;
    tmp->b = 2;
    tmp->next = klocki;
    klocki = tmp;
    
    tmp = new klocek;
    tmp->a = 3;
    tmp->b = 6;
    tmp->next = klocki;
    klocki = tmp;
    
    tmp = new klocek;
    tmp->a = 2;
    tmp->b = 9;
    tmp->next = klocki;
    klocki = tmp;

    wypisz(klocki);
    reorder(klocki);
    wypisz(klocki);
}