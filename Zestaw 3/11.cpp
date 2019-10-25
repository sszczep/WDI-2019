#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 1000;
const int START_NATURALNYCH = 1;
const int KONIEC_NATURALNYCH = 1000;

void wypelnijPseudolosowo(int t[]) {
    srand(time(NULL));

    for(int i = 0; i < MAX; i++) {
        // Wypełniamy tablicę pseudolosowymi liczbami z przedziału 1-1000
        t[i] = (rand() % (KONIEC_NATURALNYCH - START_NATURALNYCH + 1)) + START_NATURALNYCH;
    }
}

void wypelnijKolejne(int t[]) {
    for(int i = 0; i < MAX; i++) {
        // Wypełniamy tablicę kolejnymi liczbami naturalnymi
        t[i] = i;
    }
}

int main() {
    int t[MAX];

    wypelnijPseudolosowo(t);
    //wypelnijKolejne(t);

    int najdluzszyPodciag = 2;
    int obecnaDlugosc = 2;
    for(int i = 2; i < MAX; i++) {
        if(t[i] - t[i - 1] == t[i - 1] - t[i -2]) obecnaDlugosc++;
        else {
            if(obecnaDlugosc > najdluzszyPodciag) najdluzszyPodciag = obecnaDlugosc;
            obecnaDlugosc = 2;
        }
    }

    if(obecnaDlugosc > najdluzszyPodciag) najdluzszyPodciag = obecnaDlugosc;

    std::cout << najdluzszyPodciag;
}