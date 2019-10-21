#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    cout << endl << endl;

    if (n < 3) {
        return 0;
    }

    bool* liczby = new bool[n];

    for (int i = 2; i < n; i++) {
        liczby[i] = true;
    }
    
    for (int i = 2; i * i <= n; i++) {
        if (!liczby[i]) {
            continue;
        }

        for (int j = i * 2; j < n; j += i) {
            liczby[j] = false;
        }
    }

    for (int i = 2; i < n; i++) {
        if (liczby[i]) {
            cout << i << endl;
        }
    }
}