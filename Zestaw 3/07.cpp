#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 1000;

// Funkcja sprawdzająca czy każdy element tablicy zawiera co najmniej jedną cyfrę nieparzystą
bool czyZawiera(int t[]) {
    for(int i = 0; i < MAX; i++) {
        bool zawiera = false;
        while(t[i] != 0) {
            if((t[i] % 10) % 2 == 1) {
                zawiera = true;
                break;
            }

            t[i] /= 10;
        }

        if(!zawiera) return false;
    }

    return true;
}

int main() {
    // Konfigurujemy generator pseudolosowy
    srand(time(NULL));

    int t[MAX];
    for(int i = 0; i < MAX; i++) {
        // Wypełniamy tablicę pseudolosowymi liczbami z przedziału 1-1000
        t[i] = (rand() % 1000) + 1;
    }

    if(czyZawiera(t)) std::cout << "TAK";
    else std::cout << "NIE";
}