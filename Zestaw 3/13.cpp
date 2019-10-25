#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 1000;

int main() {
    // Konfigurujemy generator pseudolosowy
    srand(time(NULL));

    int t[MAX];

    for(int i = 0; i < MAX; i++) {
        // Wypełniamy tablicę pseudolosowymi liczbami nieparzystymi z przedziału 1-99

        // Najpierw generujemy liczby z przedziału 1-100
        t[i] = (rand() % 100) + 1;

        // Jeżeli liczba jest parzysta, odejmujemy od niej 1
        if(t[i] % 2 == 0) t[i]--;
    }

    // W celu ułatwienia zapisu algorytmu, zrobimy dwie pętle:
    // Jedna będzie zliczać najdłuższy podciąg z ciągiem arytmetycznym rosnącym, a druga malejącym
    int obecnaDlugosc = 2;
    int najdluzszyPodciagRosnacy = 2;
    for(int i = 2; i < MAX; i++) {
        int roznica = t[i] - t[i - 1];
        if(roznica > 0 && roznica == t[i - 1] - t[i -2]) obecnaDlugosc++;
        else {
            if(obecnaDlugosc > najdluzszyPodciagRosnacy) najdluzszyPodciagRosnacy = obecnaDlugosc;
            obecnaDlugosc = 2;
        }
    }

    if(obecnaDlugosc > najdluzszyPodciagRosnacy) najdluzszyPodciagRosnacy = obecnaDlugosc;

    obecnaDlugosc = 2;
    int najdluzszyPodciagMalejacy = 2;
    for(int i = 2; i < MAX; i++) {
        int roznica = t[i] - t[i - 1];
        if(roznica < 0 && roznica == t[i - 1] - t[i -2]) obecnaDlugosc++;
        else {
            if(obecnaDlugosc > najdluzszyPodciagMalejacy) najdluzszyPodciagMalejacy = obecnaDlugosc;
            obecnaDlugosc = 2;
        }
    }

    if(obecnaDlugosc > najdluzszyPodciagMalejacy) najdluzszyPodciagMalejacy = obecnaDlugosc;

    std::cout << najdluzszyPodciagRosnacy << " - " << najdluzszyPodciagMalejacy << " = " << najdluzszyPodciagRosnacy - najdluzszyPodciagMalejacy;
}