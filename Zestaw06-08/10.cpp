#include <iostream>
#include <cmath>

/*
10. Dana jest tablica int t[N]. Proszę napisać program zliczający liczbę “enek” o
określonym iloczynie.

Wykorzystamy pomysł z maską bitową, żeby nie zliczać dwa razy tych samych iloczynów

Funkcja pisana bez użycia rekurencji.
*/

const int N = 4;
int nki(int t[N], int iloczyn){
  int sum = 0;
  // liczymy maskę bitową długości 2^N bitów
  for(unsigned int i = 0; i < round(pow(2.0, N)); ++i){
    int tmpIloczyn = 1;
    
    for(int k = 0; k < N; ++k){
      // jeżeli dana liczba jest oznaczona jako brana w masce to mnożymy
      if(((i>>k) & 1) == 1){
        tmpIloczyn *= t[k];
      }
    }

    if(tmpIloczyn == iloczyn){ ++sum; }
  }
  return sum;
}

int main() {
  int t[N] = {
    2, 4, 2, 3
  };
  std::cout << nki(t, 12) << std::endl;
}
