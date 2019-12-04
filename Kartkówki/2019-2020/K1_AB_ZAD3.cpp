/**
 * To samo rozwiazanie jest prawidlowe dla grup A i B,
 * tzn warunek z hetmanem i krolem jest wlasciwie jednakowy.
 */
#include <cmath>
using namespace std;

const int N = 8;

int t[N][N];

bool next(int w, int k, int s) {
    if (w == N - 1) {
        return s == 0;
    }
    else {
        for (int nk = 0; nk < N; nk++) {
            if (abs(nk - k) > 1) {
                if (next(w + 1, nk, s + t[w + 1][nk])) {
                    return true;
                }
            }
        }
        return false;
    }
}

bool krol() {
    for (int k = 0; k < N; k++) {
        if (next(0, k, t[0][k])) {
            return true;
        }
    }
    return false;
}