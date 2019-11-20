#include <cmath>
using namespace std;

const int N = 100;

int waga(int n) {
    int w = 0;
    for (int i = 2; i <= sqrt(n + 1); i++) {
        if (n % i == 0) {
            w++;
        }
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n > 1) {
        w++;
    }
    return w;
}

//podzbior(t, 0, 0, 0, 0);
bool podzbior(int t[N], int s1, int s2, int s3, int i) {
    if (i == N) {
        return (s1 == s2) && (s2 == s3);
    }
    return podzbior(t, s1 + t[i], s2, s3, i + 1) ||
           podzbior(t, s1, s2 + t[i], s3, i + 1) ||
           podzbior(t, s1, s2, s3 + t[i], i + 1);
}

bool okalajaca(int t[N]) {
    int wagi[N];
    int suma;
    for (int i = 0; i < N; i++) {
        suma += wagi[i] = waga(t[i]);
    }
    //jesli suma wag jest niepodzielna przez 3 to nie da sie jej rozlozyc na 3 sumy, elo
    //dzieki Adrian R. za sprawne oko
    if (suma % 3 != 0) {
        return false;
    }
    return podzbior(wagi, 0, 0, 0, 0);
}