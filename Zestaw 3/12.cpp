#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 1000;
const int START_NATURALNYCH = 1;
const int KONIEC_NATURALNYCH = 1000;

int main() {
    // Konfigurujemy generator pseudolosowy
    srand(time(NULL));

    int t[MAX];
    for(int i = 0; i < MAX; i++) {
        // Wypełniamy tablicę pseudolosowymi liczbami z przedziału 1-1000
        t[i] = (rand() % (KONIEC_NATURALNYCH - START_NATURALNYCH + 1)) + START_NATURALNYCH;
    }

    int najdluzszyPodciag = 2;
    int obecnaDlugosc = 2;
    for(int i = 2; i < MAX; i++) {
        if(1.0 * t[i] / t[i - 1] == 1.0 * t[i - 1] / t[i -2]) obecnaDlugosc++;
        else {
            if(obecnaDlugosc > najdluzszyPodciag) najdluzszyPodciag = obecnaDlugosc;
            obecnaDlugosc = 2;
        }
    }

    if(obecnaDlugosc > najdluzszyPodciag) najdluzszyPodciag = obecnaDlugosc;

    std::cout << najdluzszyPodciag;
}