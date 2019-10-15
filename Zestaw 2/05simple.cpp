/**
 * Rozwiązanie, gdy nie wpadnie się na wzór rekurencyjny pozbywający się dziesiątek:
 * https://www.geeksforgeeks.org/last-non-zero-digit-factorial/
 * 
 * Zasada działania programu jest taka: przy liczeniu ostatnich cyfr liczby "silniowanej"
 * potrzebne jest nam parę ostatnich cyfr, dokladniej floor(log10(n))
 * 
 * To nie jest najbardziej optymalne rozwiązanie, ale jest to rozwiązanie
 * proste do realizacji bez wielkich wywodów matematycznych xD
**/

#include <iostream>
using namespace std;

/**
 * "rzędu" 1 000 000", więc 10^6 * 10 ustalamy jako maksymalną wartość n
 * wobec tego, że mnożymy liczby nie większe od 10^7 typ 
 * uint64_t (unsigned long long) powinien wystarczyć
**/
uint64_t const rzad_wielkosci = 10e6 * 10;

int n;
uint64_t nFactor = 1;

//pozbywa się zer z prawej strony, aż liczba jedności będzie != 0
uint64_t utnij_zera(uint64_t liczba) {
    while (liczba % 10 == 0) {
        liczba /= 10;
    }
    return liczba;
}

//zwraca ostatnie floor(log10(n)) cyfr różnych od 0 (przynajmniej pierwsza od prawej taka jest)
uint64_t ostatnie_x_cyfr(uint64_t liczba) {
    return utnij_zera(liczba) % rzad_wielkosci;
}

int main() {
    cout << "podaj n: ";
    cin >> n;
    cout << endl;

    if (n < 1 || n >= rzad_wielkosci) {
        cout << "niepoprawne dane wejściowe" << endl;
        return 0;
        
    }

    //operacja analogiczna do normalnej silni
    for (int i = 1; i <= n; i++) {
        nFactor *= i;
        nFactor = ostatnie_x_cyfr(nFactor);
    }

    cout << nFactor % 10 << endl;
}