#include <iostream>
#include <cmath>

using namespace std;

// Napisać program generujący i wypisujący liczby pierwsze mniejsze
// od N metodą Sita Eratostenesa
int main() {
    int n;
    cin >> n;
    cout << endl << endl;

    bool *is_prime = new bool[n];

    // domyślna wartosc - jest pierwszą
    for(size_t i = 0; i < n; ++i){
        is_prime[i] = true;
    }

    // wykreslamy kolejne wielokrotnosci liczb pierwszych zaczynajac od 2
    // sprawdzamy tylko do sqrt(n) jak Gajecki przykazal przy liczbach pierwszych
    for(size_t i = 2; i < sqrt(n); ++i){
        // jezeli nie zostala wykreslona wczesniej
        if(is_prime[i]){
            // to wykreslamy jej kolejne wielokrotnosci
            for(size_t k = 2*i; k < n; k += i){
                is_prime[k] = false;
            }
        }
    }

    // wypisujemy liczby pierwsze zaczynajac od 2
    for(size_t i = 2; i < n; ++i){
        if(is_prime[i]) {
            cout << i << endl;;
        }
    }
}