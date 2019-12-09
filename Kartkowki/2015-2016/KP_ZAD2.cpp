#include <iostream>
using namespace std;

const int N = 10;

int t[N];

int jedynki(int n) {
    int result = 0;
    while (n > 0) {
        if (n % 2 != 0) {
            result += 1;
        }
        n /= 2;
    }
    return result;
}

bool zbiory(int i, int z1, int z2, int z3) {
    if (i == N) {
        return z1 == z2 && z2 == z3;
    }
    int jeden = jedynki(t[i]);
    return zbiory(i + 1, z1 + jeden, z2, z3) ||
           zbiory(i + 1, z1, z2 + jeden, z3) ||
           zbiory(i + 1, z1, z2, z3 + jeden);
}
