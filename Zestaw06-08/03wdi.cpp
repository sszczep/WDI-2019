#include <iostream>
using namespace std;

const int N = 100;

//waga(t,23,0,"")
void waga(int t[N], int m, int p, string res) {
    if (p == N) {
        if (m == 0) {
            cout << res;
        }
    }
    else {
        waga(t, m - t[p], p + 1, res + '1');
        waga(t, m, p + 1, res + '0');
    }
}