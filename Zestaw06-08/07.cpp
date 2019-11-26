#include <iostream>
using namespace std;

const int N = 6;

//mMin = -1;
//podzbior(t, 0, "", mMin);
void podzbior(int t[N], int n, string kombinacja, int& mMin, int& s) {
    if (n == N) {
        int sumaElem = 0;
        int sumaIdx = 0;
        int moc = 0;
        for (int i = 0; i < N; i++) {
            if (kombinacja[i] == '1') {
                sumaElem += t[i];
                sumaIdx += i;
                moc++;
            }
        }
        if (moc > 0 && sumaElem == sumaIdx) {
            if (mMin == -1 || moc < mMin) {
                mMin = moc;
                s = sumaElem;
            }
        }
    }
    else {
        podzbior(t, n + 1, kombinacja + '0', mMin, s);
        podzbior(t, n + 1, kombinacja + '1', mMin, s);
    }
}

int najmniejszy(int t[N]) {
    int mMin = -1;
    int s = -1;
    podzbior(t, 0, "", mMin, s);
    return s;
}

int main() {
    int t[N] = {1, 7, 3, 5, 11, 2};
    cout << najmniejszy(t);
}