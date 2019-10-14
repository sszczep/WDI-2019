#include <iostream>

using namespace std;

//generujemy ciąg o początkowych wyrazach a i b analogiczny do ciągu fibonacciego
bool znajdz_w_fib(int a, int b, int szukana) {
    int c;
    while (a <= szukana) {
        if (a == szukana) {
            return true;
        }
        c = a+b;
        a = b;
        b = c;
    }
    return false;
}

int main() {
    int szukana;
    cin >> szukana;

    int suma = 1;
    //dla każdej sumy a + b poczynając od 1...
    while (true) {
        int a = 0;
        int b = suma;
        //...sprawdzamy ciągi fibonacciego o wyrazach pocz. a i b, od a=0, b=suma do a=suma-1, b=1
        while (b > 0) {
            if (znajdz_w_fib(a, b, szukana)) {
                cout << "znaleziono przy sumie " << a+b << ", wyrazy a " << a << " " << b << endl ;
                return 0;
            }
            a++;
            b--;
        }

        suma++;
    }
}