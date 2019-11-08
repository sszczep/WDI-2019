#include <iostream>
#include <cmath>

const uint64_t n = 1000;

int main() {
    // Zliczamy ile cyfr ma n!
    // Dzięki temu wiemy o jakiej wielkości tablicę musimy zaalokować
    // Wykorzystamy własność, że (część całkowita logarytmu o podstawie 10 z liczby x) + 1 jest równa ilości cyfr liczby x
    double temp = 0;
    for(uint64_t i = 1; i <= n; i++) temp += log10(i);
    uint64_t digitsCount = temp + 1;

    // Alokujemy tablicę o wielkości digitsCount
    uint64_t *digits = new uint64_t[digitsCount]();
    digits[0] = 1;
    
    for(uint64_t multiplier = 2; multiplier <= n; multiplier++) {
        // Mnożymy kolejne cyfry mnożnej przez mnożnik i iloczyn zapisujemy
        // Wąskie gardło algorytmu - iloczyn digits[i] i multiplier musi być mniejszy niż 2^64 -1
        for(uint64_t i = 0; i < digitsCount; i++) digits[i] *= multiplier;

        // Wyłączamy pełne dziesiątki do kolejnych elementów tablicy
        for(uint64_t i = 0; i < digitsCount - 1; i++) {
            digits[i + 1] += digits[i] / 10;
            digits[i] %= 10;
        }
    }

    std::cout << "Ilość cyfr n!: " << digitsCount << "\nn! = ";

    uint64_t i = digitsCount - 1;
    while(true) {
        std::cout << digits[i];

        if(i == 0) break;
        i--;
    }

    // Zwalniamy pamięć po wykonaniu programu
    delete[] digits;
}