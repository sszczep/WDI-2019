#include <iostream>
#include <cmath>

/*
10. Dana jest tablica int t[N]. Proszę napisać program zliczający liczbę “enek” o
określonym iloczynie.

11. Proszę zmodyfikować poprzedni program aby wypisywał znalezione n-ki. 
*/

const int N = 4;
int nki(int t[N], int iloczyn){
  int sum = 0;
  for(unsigned int i = 0; i < round(pow(2.0, N)); ++i){
    int tmpIloczyn = 1;
    // ¯\_(ツ)_/¯
    std::string s = "";

    for(int k = 0; k < N; ++k){
      if(((i>>k) & 1) == 1){
        s += std::to_string(t[k]) + ", ";
        tmpIloczyn *= t[k];
      }
    }

    if(tmpIloczyn == iloczyn){
      std::cout << s << std::endl;
      ++sum;
    }
  }
  return sum;
}

int main() {
  int t[N] = {
    2, 4, 2, 3
  };
  std::cout << nki(t, 12) << std::endl;
}
