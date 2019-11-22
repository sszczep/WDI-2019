#include <iostream>
#include <iomanip>

const int N = 8;

void print(int arr[N][N]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      std::cout << std::setfill(' ') << std::setw(5) << arr[i][j];
    }
    std::cout << std::endl << std::endl;
  }
}

bool skoczek(int arr[N][N], int posX = 0, int posY = 0, int left = N*N) {
  if(left == 0) return true;

  if(posX >= N || posX < 0) return false;
  if(posY >= N || posY < 0) return false;
  if(arr[posX][posY] != 0) return false;

  arr[posX][posY] = N*N - left + 1;
  left--;

  // Wszystkie możliwe ruchy skoczka
  if(skoczek(arr, posX + 1, posY + 2, left)) return true;
  if(skoczek(arr, posX + 1, posY - 2, left)) return true;
  if(skoczek(arr, posX - 1, posY + 2, left)) return true;
  if(skoczek(arr, posX - 1, posY - 2, left)) return true;
  if(skoczek(arr, posX + 2, posY + 1, left)) return true;
  if(skoczek(arr, posX + 2, posY - 1, left)) return true;
  if(skoczek(arr, posX - 2, posY + 1, left)) return true;
  if(skoczek(arr, posX - 2, posY - 1, left)) return true;

  arr[posX][posY] = 0;

  return false;
}

int main() {
  // Tablica przechowywująca numer ruchu skoczka na pole [x][y]
  int arr[N][N] = {0};

  // Startujemy dla pozycji 3, 3 -> algorytm szybciej się wykonuje
  // Wartość dobrana eksperymentalnie
  skoczek(arr, 3, 3);
  print(arr);
}
