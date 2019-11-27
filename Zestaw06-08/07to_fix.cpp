#error "To wcale nie jest dobrze"
#include <iostream>

const int N = 4;

bool najmniejszaSuma(int t[], int &sum, int valueSum = 0, int indexSum = 0, int currentIndex = 0) {
  // Jeżeli sumy są sobie równe i są różne od zera to zwracamy prawdę
  if(valueSum == indexSum && valueSum != 0) {
    sum = valueSum;
    return true;
  }

  // Jeżeli osiągneliśmy koniec tablicy to zwracamy fałsz
  if(currentIndex == N) return false;

  return
    najmniejszaSuma(t, sum, valueSum, indexSum, currentIndex + 1)
    || najmniejszaSuma(t, sum, valueSum + t[currentIndex], indexSum + currentIndex, currentIndex + 1);
}

int main() {
  int t[N] = {1, 3, 1, 2};

  int sum = 0;
  bool exists = najmniejszaSuma(t, sum);

  if(exists) std::cout << sum;
  else std::cout << "Brak takiej sumy";
}
