#include <iostream>

using namespace std;

int main() {
  int x;
  cin >> x;

  // będziemy liczyć ciąg fibbonaciego, ale przechowywać liczby na koncach
  // aktualnie liczonego przedzialu a1, b1 - wskaznik dolny a2, b2 - wskaznik
  // gorny
  // przesuwamy wskaznik u gory, kiedy suma < zadanej, przesuwamy wskaznik u dolu, odejmujac wyraz ciagu, ktory juz nie jest w zakresie, mniejszajac sume
  // konczymy gdy wskaznik dolny przejdzie dalej niz gorny
  uint a1 = 0, b1 = 1, a2 = 0, b2 = 1;

  int sum = 0;

  while ((b1 <= b2) && (sum >= 0)) {
    if (sum == x) {
        cout << "istnieje"; 
      return 0;
    }
    if (sum < x) {
      sum += b2; // dodajemy do sumy kolejny wyraz

      b2 += a2; // i podmieniamy ten wyraz na następny
      a2 = b2 - a2;  
    } else if (sum > x) {
      sum -= b1;  // odejmujemy "odcieta" liczbe z ciagu

      b1 += a1; //nast wyraz ciagu
      a1 = b1 - a1;  
    }
  }

  cout << "nie istnieje" << endl;
  return 1;
}