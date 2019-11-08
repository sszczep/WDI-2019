#include <iostream>

using namespace std;

int ilosc_cyfr[10] = {0};

int a, b;

int main() {
  cin >> a;
  cin >> b;

  while (a > 0) {
    ++ilosc_cyfr[a % 10];
    a /= 10;
  }

  while (b > 0) {
    --ilosc_cyfr[b % 10];
    b /= 10;
  }

  for (int x : ilosc_cyfr) {
    if (x != 0) {
      cout << "nie sa";
      return 0;
    }
  }
  cout << "sa";
}
