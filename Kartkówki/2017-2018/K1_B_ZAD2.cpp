#include <iostream>

const int N = 10;

bool czyPalindrom(int tab[N], int start, int koniec) {
  for(int i = start; i < start + (koniec - start) / 2; i++) {
    if(tab[i] != tab[koniec + start - i]) return false;
  }

  return true;
}

int podciag(int tab[N]) {
  int pocz_nieparzystych = -1;
  int najdl = 0;

  for(int i = 0; i < N; i++) {
    if(pocz_nieparzystych == -1 && tab[i] % 2 == 1) pocz_nieparzystych = i;
    if(tab[i] % 2 == 1) {
      for(int j = pocz_nieparzystych; j <= i; j++) {
        if(czyPalindrom(tab, j, i))
          if((i - j) > najdl) najdl = i - j;
      }
    } else pocz_nieparzystych = -1;
  }

  return najdl + 1;
}

int main() {
  int tab[N] = { 4, 3, 1, 3, 5, 1, 1, 5, 1, 0 };

  std::cout << podciag(tab);
}
