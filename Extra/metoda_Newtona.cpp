// Wzór rekurencyjny metody Newtona
// x_(k+1) = x_k - f(x_k) / f'(x_k)
// Wzór rekurencyjny na pierwiastek n stopnia
// x_(k+1) = 1/n * ((n - 1) * x_k + a / x_k ^ (n - 1))
// Wzór rekurencyjny na piewiastek 3 stopnia
// x_(k+1) = 1/3 * (2 * x_k + a / x_k ^ 2)

#include <iostream>
#include <cmath>

const double eps = 1e-6;
unsigned int counter = 0;

double newton(double a, double x = 1.0) {
    counter++;

    // Liczymy kolejną wartość funkcji
    double x1 = (2 * x + a / (x * x)) / 3.0;

    // Jeżeli różnica liczb jest wystarczająco mała (<= eps), zwracamy tę liczbę
    if(fabs(x - x1) <= eps) return x1;

    // Jeżeli dokładność jest jeszcze niewystarczająca, znowu wykonujemy funkcję, aby policzyć kolejną wartość
    return newton(a, x1);
}

int main() {
    double a;
    std::cin >> a;

    std::cout << "Liczba wywołań rekurencyjnych = " << counter << std::endl;
    std::cout << "Metoda Newtona: " << a << "^(1/3) = " << newton(a) << std::endl;
    // Poniższa linijka służy sprawdzeniu, czy nasze obliczenia są poprawne
    std::cout << "Biblioteka cmath: " << a << "^(1/3 = " << pow(a, 1/3.0) << std::endl;
}