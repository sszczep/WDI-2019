const int N = 10;

int t1[N];
int t2[N];

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

