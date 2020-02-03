#include <iostream>

// Funkcja sprawdzajaca czy pierwsza
bool is_prime(int n) {
    return (n == 2 || n == 3 || n == 5 || n == 7);
}

// Funkcja sprawdzajaca czy mamy juz taka liczbe w tablicy
bool includes(int n, int tab[], int len) {
    for(int i = 0; i < len; i++)
        if(n == tab[i]) return true;

    return false;
}

void func(int tab[], int len = 1) {
    // Jezeli osiagnelismy ciag o dlugosci 9, wypisujemy go i zakanczamy dzialanie funkcji
    if(len == 9) {
        for(int i = 0; i < 9; i++) std::cout << tab[i];
        std::cout << std::endl;
        return;
    }

    // Szukamy liczb ktore mozna wpisac na nastepna pozycje
    for(int i = 2; i <= 9; i++) {
        // Jezeli liczba jest juz w tablicy, pomijamy ja
        if(includes(i, tab, len)) continue;

        // Jezeli liczba rozni sie o mniej niz 2 od ostatniej liczby, pomijamy ja
        if(abs(tab[len - 1] - i) <= 2) continue;

        // Jezeli liczba i ostatnia liczba sa liczbami pierwszymi, pomijamy ja
        if(is_prime(tab[len - 1]) && is_prime(i)) continue;

        // W przeciwnym wypadku dodajemy liczbe
        tab[len] = i;
        func(tab, len + 1);
    }
}

int main() {
    int tab[9];
    tab[0] = 1;
    func(tab);
}
