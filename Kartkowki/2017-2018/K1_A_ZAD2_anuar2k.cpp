#include <iostream>
using namespace std;

const int N = 8;
int tab[N];

int idx(int s, int k) {
    int dl = k - s + 1;
    for (int i = dl; i > 0; i--) {
        for (int pocz = s; pocz <= k - i + 1; pocz++) {
            int sTab = 0;
            int sIdx = 0;
            for (int j = pocz; j < pocz + i; j++) {
                sTab += tab[j];
                sIdx += j;
            }
            if (sTab == sIdx) {
                return i;
            }
        }
    }
    return 0;
}

int dl() {
    int pocz = 0;
    int maxDl = 0;
    while (pocz < N) {
        int s = pocz;
        int k = pocz;
        while (k < N - 1 && tab[pocz] < tab[pocz + 1]) {
            pocz++;
            k = pocz;
        }
        int dl = idx(s, k);
        if (dl > maxDl) {
            maxDl = dl;
        }
        pocz++;
    }
    return maxDl;
}

int main() {
    for (int i = 0; i < N; i++) {
        cin >> tab[i];
    }
    cout << endl << dl();
}
