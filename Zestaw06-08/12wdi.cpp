#include <iostream>

using namespace std;

//roz(4);
void roz(int n, int last = 1, string s = "") {
    if (n == 0) {
        cout << s << endl;
    }
    else {
        for (int i = last; i <= n; i++) {
            roz(n - i, i, s + ',' + to_string(i));
        }
    }
}

int main() {
    int n;
    cin >> n;
    roz(n);
}