#include <iostream>
#include <vector>

bool isFibo(int n) {
  std::vector <int> fiboElements = { 1, 1 };

  int sum = 2;
  while(sum < n) {
    int fiboLength = fiboElements.size();
    int nextFibo = fiboElements[fiboLength - 1] + fiboElements[fiboLength - 2];
    fiboElements.push_back(nextFibo);
    sum += nextFibo;
  }

  int idx = 0;
  while(sum > n) sum -= fiboElements[idx++];

  if(sum == n) return true;
  else return false;
}

int main() {
  int n;
  std::cin >> n;

  while(isFibo(++n));

  std::cout << n;
}
