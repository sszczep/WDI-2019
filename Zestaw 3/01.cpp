#include <iostream>

// Napisać program zamieniający liczbę naturalną z systemu 10 na
// podstawę 2-16
using namespace std;

void print_in_base(unsigned n, unsigned base) {
  const string glyphs = "0123456789abcef";
  string transformed = "";
  while (n > 0) {
    transformed += glyphs[n % base];
    n /= base;
  }

  for (int i = transformed.length() - 1; i >= 0; --i) {
    cout << transformed[i];
  }
  cout << endl;
}

int main() {
  unsigned n;
  cin >> n;

  for (size_t i = 2; i <= 16; ++i) {
    print_in_base(n, i);
  }
}
