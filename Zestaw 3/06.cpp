#include <iostream>

int main() {
    // W zadaniu nie mamy podanej maksymalnej wielkości wprowadzanych liczb więc użyjemy
    // zmiennych typu uint64_t
    // Wiemy z treści zadania, że wprowadzane liczby są naturalne, więc możemy pominąć znak (unsigned)
    // Sidenote: Jeśli liczby przekraczałyby zakres zmiennej typu uint64_t, należy użyć stringów i porównywać leksykograficznie

    uint64_t input;
    uint64_t tab[10] = { 0 };

    do {
        std::cin >> input;

        // Najpierw sprawdzamy czy wprowadzona liczba nie jest mniejsza niż nasze top10
        // Jeśli tak to ją pomijamy
        if(input < tab[9]) continue;

        for(int i = 0; i < 10; i++) {
            // Jeżeli wprowadzona liczba jest większa od liczby na pozycji tab[i]
            if(input > tab[i]) {
                // Cofamy elementy o indeksach i...9 o jedną pozycję do tyłu
                for(int j = 9; j > i; j--) tab[j] = tab[j - 1];

                // Przypisujemy nową wartość do elementu tablicy o indeksie i
                tab[i] = input;

                // Wychodzimy z pętli for
                break;
            }
        }
    } while(input != 0);

    // Wypisujemy wynik
    std::cout << tab[9];
}
