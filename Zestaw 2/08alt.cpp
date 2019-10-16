#include <iostream>

using namespace std;

int a, b, n;
int reszta;

int main() {
    cin >> a;
    cin >> b;
    cin >> n;

    cout << a/b << ',';

    reszta = a % b * 10;
    while (n > 0) {
        cout << reszta/b;
        reszta %= b;
        reszta *= 10;
        n--;
    }
}
