/**
 * Notka od autora: podejscie autorskie, polegajace na tym, ze liczbe "silniowana"
 * reprezentuje jako tablice "trojek", tj. kazda trojka to 3 kolejny cyfry liczby
 * "silniowanej". Mnoze kazda z tych trojek przez kolejne liczby do n i po kazdym
 * mnozeniu danej trojki cyfry niemieszczace sie w tej trojce dodaje do kolejnej.
 * 
 * Na pewno grupowanie liczby na trojki to glupie ograniczenie, ale ten sposob mnożenia
 * był łatwy do rozpisania sobie w zeszycie XD
 */

#include <iostream>

using namespace std;

int trojki[1000] = {0};
int n;

int main() {
    cin >> n;
    trojki[0] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 998; j >= 0; j--) {
            int czesc_silni = trojki[j] * i;
            int nowa_trojka = czesc_silni % 1000;
            int dodatek_wyzej = czesc_silni / 1000;
            trojki[j] = nowa_trojka;

            int k = j + 1;
            while (dodatek_wyzej > 0) {
                czesc_silni = trojki[k] + dodatek_wyzej;
                nowa_trojka = czesc_silni % 1000;
                dodatek_wyzej = czesc_silni / 1000;

                trojki[k] = nowa_trojka;
                k++;
            }
        }
    }

    int poczatek_silni;
    for (int i = 999; i >= 0; i--) {
        if (trojki[i] != 0) {
            poczatek_silni = i;
            break;
        }
    }

    for (int i = poczatek_silni; i >= 0; i--) {
        if (i != poczatek_silni) {
            if (trojki[i] < 100) {
                cout << '0';
            }
            if (trojki[i] < 10) {
                cout << '0';
            }
        }
        cout << trojki[i];
    }
}