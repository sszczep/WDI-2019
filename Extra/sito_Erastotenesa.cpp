#include <iostream>
#include <array>
#include <cmath>

const int n = 1000000;

int main() {
    // Deklarujemy tablicę typu bool z ilością elementów n (uzyskujemy zakres 0...(n - 1)), n = 10e6
    std::array<bool, n> numbers;

    // Ustawiamy wszystkie elementy tablicy numbers na wartość logiczną true
    std::fill(std::begin(numbers), std::end(numbers), true);

    // Dla uproszczenia algorytmu pomijamy pierwszy element tablicy (dzięki temu indeks elementu tablicy będzie równy liczbie którą reprezentuje)
    // Pomijamy również drugi element (1 nie jest liczbą pierwszą), dlatego zaczynamy od trzeciego elementu (n = 2)

    // Sprawdzamy wszystkie liczby <= sqrt(n) - liczby większe niż pierwiastek ostatniej liczby nie będą już dzielnikami innych liczb
    for(unsigned int i = 2; i < sqrt(n); i++) {
        // Jeżeli liczba jest oflagowana jako false, to znaczy że nie jest liczbą pierwszą i ją pomijamy
        if(numbers[i] == false) continue;

        // Liczba jest pierwsza, wykreślamy jej wielokrotności
        for(unsigned int j = i * 2; j < n; j += i) {
            if(j % i == 0) numbers[j] = false;
        }
    }

    // Powinniśmy uzyskać tablicę, w której wartość logiczna = true oznacza, że liczba równa indeksowi tego elementu jest liczbą pierwszą
    // Wypisujemy te elementy
    for(unsigned int i = 2; i < n; i++) {
        if(numbers[i]) std::cout << i << " ";
    }
}