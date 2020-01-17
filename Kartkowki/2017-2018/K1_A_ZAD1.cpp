#include <iostream>
#include <string>

bool compareInBase(int x, int y, int base) {
  std::string xStr = "";
  int length = 0;

  while(x != 0) {
    xStr[length++] = (char)(x % base);
    x /= base;
  }

  while(y != 0) {
    char yChar = y % base;
    for(int i = 0; i < length; i++)
      if(xStr[i] == yChar) return false;
    y /= base;
  }

  return true;
}

int main() {
  int x, y;
  std::cin >> x >> y;

  for(int i = 2; i <= 16; i++) {
    if(compareInBase(x, y, i)) {
      std::cout << i;
      return 0;
    }
  }

  std::cout << "Liczby nie są różnocyfrowe w żadnej podstawie";
}
