#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 1000;

// Funkcja sprawdzająca czy istnieje element tablicy zawierający wyłącznie cyfry nieparzyste
bool czyIstnieje(int t[]) {
    for(int i = 0; i < MAX; i++) {
        bool wylacznieNieparzyste = true;
        while(t[i] != 0) {
            if((t[i] % 10) % 2 == 0) {
                wylacznieNieparzyste = false;
                break;
            }

            t[i] /= 10;
        }

        if(wylacznieNieparzyste) return true;
    }

    return false;
}

int main() {
    // Konfigurujemy generator pseudolosowy
    srand(time(NULL));

    int t[MAX];
    for(int i = 0; i < MAX; i++) {
        // Wypełniamy tablicę pseudolosowymi liczbami z przedziału 1-1000
        t[i] = (rand() % 1000) + 1;
    }

    if(czyIstnieje(t)) std::cout << "TAK";
    else std::cout << "NIE";
}