#include <iostream>

const int N = 9;

int najdlPodciag(int tab[N], int start = 0) {
  int longest = 0;
  int current = 1;
  int sumIdx = start;
  int sumVal = tab[start];

  for(int i = start + 1; i < N; i++) {
    if(tab[i] > tab[i - 1]) {
      current++;
      sumIdx += i;
      sumVal += tab[i];
    } else {
      current = 1;
      sumIdx = i;
      sumVal = tab[i];
    }

    if(sumIdx == sumVal && current > longest) longest = current;
  }

  return longest;
}

int najdlPodciagKoncowy(int tab[N]) {
  int longest = 0;
  for(int i = 0; i < N; i++) {
    int current = najdlPodciag(tab, i);
    if(current > longest) longest = current;
  }

  return longest;
}

int main() {
  int tab[N] = { 0, 0, 0, 3, 4, 8, 6, 7, 8 };
  std::cout << najdlPodciagKoncowy(tab);
}
