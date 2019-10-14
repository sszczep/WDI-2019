#include <iostream>
#include <vector>

std::vector <unsigned int> fibonacci(unsigned int x, std::vector <unsigned int> &array) {
    // Wyznaczamy sumę dwóch poprzednich elementów ciągu
    unsigned int size = array.size();
    unsigned int a = array[size - 1], b = array[size - 2];
    unsigned int c = a + b;

    // Jeżeli suma jest mniejsza od szukanej liczby, dodajemy ją do vectora i wyliczamy rekurencyjnie kolejny element ciągu
    if(c < x) {
        array.push_back(c);
        return fibonacci(x, array);
    // Jeżeli suma jest równa szukanej liczbie, dodajemy ją do vectora i go zwracamy
    } else if(c == x) {
        array.push_back(c);
        return array;
    // Jeżeli suma jest większa od szukanej liczby, zwracamy vector
    } else return array;
}

int main() {
    // Wczytujemy poszukiwany iloczyn
    unsigned int x;
    std::cin >> x;

    // Deklarujemy vector z dwoma początkowymi wartościami - 1 i 1
    std::vector <unsigned int> array (2, 1);

    // Wypełniamy vector kolejnymi wyrazami ciągu Fibonacciego <= x
    fibonacci(x, array);

    // Sprawdzamy czy liczba x jest iloczynem dowolnych dwóch wyrazów ciągu Fibonacciego - O(n^2)
    for(unsigned int i = 0; i < array.size(); i++) {
        for(unsigned int j = i + 1; j < array.size(); j++) {
            unsigned int multiplied = array[i] * array[j];
            
            if(multiplied == x) {
                std::cout << "Liczba " << x << " jest iloczynem dowolnych dwóch wyrazów ciągu Fibonacciego (" << array[i] << " i " << array[j] << ")";
                return 0;
            } else if(multiplied > x) break;
        }
    }

    std::cout << "Liczba " << x << " nie jest iloczynem dowolnych dwóch wyrazów ciągu Fibonacciego";
}