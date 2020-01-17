#include <iostream>

using namespace std;

const int N = 10;

bool podzbiory(int t[N], int s1 = 0, int s2 = 0, int n1 = 0, int n2 = 0, int i = 0) {
    if (i == N) {
        if (n1 != 0 && n1 == n2 && s1 == s2) {
            return true;
        }
        return false;
    }
    else {
        return podzbiory(t, s1 + t[i], s2       , n1 + 1, n2    , i + 1) ||
               podzbiory(t, s1       , s2 + t[i], n1    , n2 + 1, i + 1) ||
               podzbiory(t, s1       , s2       , n1    , n2    , i + 1);
    }
}

int main() {
    int t[N] = {0, 0, 1, 2, 2, 1, 0, 0, 3, 5};
    cout << podzbiory(t);
}