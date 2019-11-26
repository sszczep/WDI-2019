#include <iostream>
using namespace std;

const int BOK = 4;

int krol(int t[BOK][BOK], int k, int w = 0, int koszt = 0) {
    if (k < 0 || k >= BOK) {
        return -1;
    }
    koszt += t[w][k];
    if (w == BOK - 1) {
        return koszt;
    }
    int koszta[3];
    koszta[0] = krol(t, k - 1, w + 1, koszt);
    koszta[1] = krol(t, k    , w + 1, koszt);
    koszta[2] = krol(t, k + 1, w + 1, koszt);
    int min = -1;
    bool pierwszy = true;
    for (int i = 0; i < 3; i++) {
        if (koszta[i] != -1 && (koszta[i] < min || pierwszy)) {
            min = koszta[i];
            pierwszy = false;
        }
    }
    return min;
}

int main() {
    int t[BOK][BOK];
    int k;
    cin >> k;
    for (int i = 0; i < BOK; i++) {
        for (int j = 0; j < BOK; j++) {
            cin >> t[i][j];
        }
    }
    cout << krol(t, k);
}