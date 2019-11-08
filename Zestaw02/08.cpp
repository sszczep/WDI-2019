#include <cmath>
#include <iostream>

using namespace std;

int main() {
  unsigned a, b, n;
  cout << "Podaj a: ";
  cin >> a;
  cout << "Podaj b: ";
  cin >> b;
  cout << "Podaj n: ";
  cin >> n;

  // wypisz czesc calkowita
  cout << a / b << ".";

  // wylicz reszte pod ulamki
  a = (a % b) * 10;
  // dopoki dokladnosc > 0
  while (n--) {
    // wypisz kolejna czesc dziesietna
    cout << a / b;
    // wylicz kolejna reste
    a = (a % b) * 10;
  }

  cout << endl;
}
