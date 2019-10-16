#include <iostream>
using namespace std;

int main() {
  uint n;
  cin >> n;

  uint i = 1, sqrt = 0, res = -1;
  while (sqrt <= n) {
    sqrt += i;
    i += 2;
    ++res;
  }

  cout << res << endl;
}