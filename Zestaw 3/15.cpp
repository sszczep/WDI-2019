#include <iostream>
#include <random>

using namespace std;

const int DNI = 365;

bool urodziny[DNI];
unsigned long n_przebiegow;
int n_osob;

int przypadki = 0;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, DNI - 1);

void wyczysc_urodziny() {
    for (int i = 0; i < DNI; i++) {
        urodziny[i] = false;
    }
}

int main() {
    cout << "Ile przebiegow?" << endl;
    cin >> n_przebiegow;
    cout << "Ile osob?" << endl;
    cin >> n_osob;

    for (unsigned long i = 0; i < n_przebiegow; i++) {
        wyczysc_urodziny();

        for (int j = 0; j < n_osob; j++) {
            int dzien_urodzin = dis(gen);

            if (urodziny[dzien_urodzin]) {
                przypadki++;
                break;
            }
            else {
                urodziny[dzien_urodzin] = true;
            }
        }
    }

    cout << "Szansa: " << (double)przypadki * 100 / n_przebiegow << '%';
}