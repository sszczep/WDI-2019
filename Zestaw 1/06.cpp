#include <cmath>
#include <iostream>

using namespace std;

int main() {
  const double n = 2019;

  // epsilon do zatrzymania obliczen
  const double eps = 0.0001;

  // zaczynamy od połowy 2019
  double x = n / 2;
  // liczymy roznice miedzy x^x - 2019
  double diff = pow(x, x) - n;

  // dopoki roznica wieksza od epsilona
  while (abs(diff) > eps) {
    // jezeli x^x > 2019, odejmij polowe x od x (wybierz I polowe)
    if (diff > n) {
      x -= x / 2;
      // jezeli x^x <>> 2019, dodaj polowe x od x (wybierz II polowe)

    } else if (diff < n) {
      x += x / 2;
    }
    // oblicz nowa roznice
    diff = pow(x, x) - n;
  }
  cout << x << endl;
}