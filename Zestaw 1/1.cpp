#include <iostream>

const unsigned int max = 1000000;

void fibonacci(unsigned int a = 0, unsigned int b = 1) {
    // Wypisujemy obecny element ciągu
    std::cout << b << " ";

    // Sumujemy dwa ostatnie wyrazy i przechowujemy je w zmiennej "a"
    a += b;

    // Jeżeli suma dwóch ostatnich wyrazów przekroczyła maksymalną wartość (10^6), wychodzimy z funkcji
    if(a >= max) return;

    // Rekurencyjne wywołanie funkcji, poszukujemy kolejny element ciągu
    fibonacci(b, a);
}

int main() {
    // Wywołujemy funkcję
    fibonacci();
}