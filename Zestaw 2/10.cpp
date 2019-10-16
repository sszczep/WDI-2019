#include <iostream>

double f(double x) { return 1 / x; }

int main() {
  double k;
  std::cout << "Podaj k: ";
  std::cin >> k;

  double dx = 1e-7;

  double area = 0;
  for (double i = 1; i < k; i += dx) {
    area += dx * f(i + dx);
  }
  std::cout << "dX: " << dx << " => " << area << std::endl;

  return 0;
}
