#include <iostream>

const unsigned int x = 2019;

bool fibonacci(unsigned int a, unsigned int b) {
    if(a == 0 && b == 0) return false;

    a += b;

    // Jeżeli suma wyrazów jest większa od szukanej liczby, zwracamy fałsz (nie ma już możliwości aby taka liczba się pojawiła)
    if(a > x) return false;
    // Jeżeli suma wyrazów jest równa szukanej liczbie, zwracamy prawdę, istnieją takie liczby początkowe a i b aby wystąpił
    if(a == x) return true;
    // W innym przypadku liczymy rekurencyjnie kolejny wyraz ciągu
    return fibonacci(b, a);
}

int main() {
    // Zaczynamy od sumy równej 1
    unsigned int suma = 1;

    // Aby nie utknąć w niekończącej się petli, ustalamy warunek że suma nie może być większa od szukanej liczby (jako że ciąg jest rosnący, już się nie pojawi)
    while(suma <= x) {
        // Sprawdzamy czy dla danej sumy, wystąpi wyraz równy x (w tym przypadku 2019)
        for(unsigned int a = 0; a <= suma; a++) {
            for(unsigned int b = 0; b <= suma - a; b++) {
                // Jeżeli funkcja fibonacci zwróci prawdę, tzn. że znaleźliśmy takie liczby początkowe a i b aby spełniały nasze założenie, wyświetlamy odpowiedni komunikat i zakańczamy działanie programu
                if(fibonacci(a, b)) {
                    std::cout << "a = " << a << " b = " << b;
                    return 0;
                }
            }
        }

        // Jeżeli nie wystąpił, zwiększamy sumę o 1 i kontynuujemy poszukiwania
        suma++;
    }

    // Jeśli doszliśmy do tego etapu, to znaczy, że nie ma takich liczb a i b spełniających nasze założenie
    std::cout << "Nie istnieją takie liczby początkowe a i b aby wystąpił wyraz równy " << x;
}