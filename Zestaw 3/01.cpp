#include <iostream>
#include <iomanip>

// Napisać program zamieniający liczbę naturalną z systemu 10 na
// podstawę 2-16
using namespace std;

void print_in_base(unsigned n, unsigned base) {
    const string glyphs = "0123456789abcdef";
    string transformed = "";
    while (n > 0) {
        transformed += glyphs[n % base];
        n /= base;
    }

    cout << setw(2) << base << " - ";
    for (int i = transformed.length() - 1; i >= 0; --i) {
        cout << transformed[i];
    }
    cout << endl;
}

int main() {
    unsigned n;
    cin >> n;
    cout << setfill('0');

    for (size_t i = 2; i <= 16; ++i) {
        print_in_base(n, i);
    }
}
