#include <iostream>
using namespace std;

const int N = 13;

bool isPrime(int n) {
    if (n <= 3) {
        return n > 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void _sumy(int t1[N], int t2[N], int i, int sum, int& count) {
    if (i == N) {
        if (isPrime(sum)) {
            count++;
            cout << sum << endl;
        }
    }
    else {
        _sumy(t1, t2, i + 1, sum + t1[i]        , count);
        _sumy(t1, t2, i + 1, sum + t2[i]        , count);
        _sumy(t1, t2, i + 1, sum + t1[i] + t2[i], count);
    }
}

int sumy(int t1[N], int t2[N]) {
    int count = 0;
    _sumy(t1, t2, 0, 0, count);
    return count;
}