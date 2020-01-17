#include <iostream>
using namespace std;

//sa tu dwie wersje: moj zapis z kartkowki i troche sprytniejsze nizej

const int N = 10;

int t1[N];
int t2[N];

//zapis z kartkowki, zapomnialem o sqrt(n)
bool rozk(int n) {
    if (n < 2) {
        return false;
    }
    int rozk = 0;
    int dzielnik = 2;
    while (n > 1) {
        while (n % dzielnik == 0) {
            rozk++;
            n /= dzielnik;
            if (rozk > 2) {
                return false;
            }
        }
        dzielnik++;
    }
    return rozk == 2;
}

//pewnie da sie madrzej, ale to pierwsza intuicja i to co zapisalem na kartkowce XD
bool da_sie() {
    int dl = 1;
    while (dl <= N) {
        for (int pocz1 = 0; pocz1 <= N - dl; pocz1++) {
            for (int pocz2 = 0; pocz2 <= N - dl; pocz2++) {
                int s1 = 0;
                int s2 = 0;

                for (int i = pocz1; i < pocz1 + dl; i++) {
                    s1 += t1[i];
                }
                for (int i = pocz2; i < pocz2 + dl; i++) {
                    s2 += t2[i];
                }
                //ewentualnie if (rozk(s1+s2)) - zalezy od interpretacji
                if (rozk(s1) && rozk(s2)) {
                    return true;
                }
            }
        }
        dl++;
    }
    return false;
}

//TROCHĘ MĄDRZEJ I SZYBCIEJ, tzn dobra faktoryzacja i sumy prefiksowe

//czy liczba jest iloczynem 2 liczb pierwszych? rozwiazanie na max pkt akceptowana przez Garka, z zajec
bool rozk2(int n) {
    int lim = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            lim++;
            if (lim > 2) {
                return false;
            }
            n /= i;
        }
    }
    if (n > 1) {
        lim++;
    }
    return lim == 2;
}

bool da_sie2(int t1[N], int t2[N]) {
    int p1[N], p2[N]; //sumy prefiksowe
    p1[0] = t1[0];
    p2[0] = t2[0];
    for (int i = 1; i < N; i++) {
        p1[i] = p1[i - 1] + t1[i];
        p2[i] = p2[i - 1] + t2[i];
    }

    int dl = 1;
    while (dl <= 1) {
        for (int pocz1 = 0; pocz1 <= N - dl; pocz1++) {
            for (int pocz2 = 0; pocz2 <= N - dl; pocz2++) {
                int s1 = p1[pocz1 + dl - 1] - (pocz1 > 0 ? p1[pocz1 - 1] : 0);
                int s2 = p2[pocz2 + dl - 1] - (pocz2 > 0 ? p2[pocz2 - 1] : 0);

                //ewentualnie if (rozk(s1+s2)) - zalezy od interpretacji
                if (rozk2(s1) && rozk2(s2)) {
                    return true;
                }
            }
        }
        dl++;
    }
}