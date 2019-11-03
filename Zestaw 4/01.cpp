/**
 * Program korzysta z faktu, ze w kazda strone bedziemy kolejno
 * wpisywac MAX, MAX-1, MAX-1, MAX-2, MAX-2 ... 1, 1 liczb.
 */
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 11;

int main() {
    int t[MAX][MAX];
    int dl_boku = MAX;
    //0 - dol, 1 - prawo, 2 - gora, 3 - lewo (counterclockwise)
    int kierunek = 0;
    int naturalna = 1;
    int w = -1;
    int k = 0;

    while (dl_boku > 0) {
        int do_konca_boku = dl_boku;
        while (do_konca_boku > 0) {
            switch (kierunek) {
                case 0:
                    w++;
                    break;
                case 1:
                    k++;
                    break;
                case 2:
                    w--;
                    break;
                case 3:
                    k--;
                    break;
            }
            t[w][k] = naturalna;
            naturalna++;
            do_konca_boku--;
        }

        if (kierunek % 2 == 0) {
            dl_boku--;
        }

        kierunek = (kierunek + 1) % 4;
    }

    int szer;
    while (naturalna > 0) {
        naturalna /= 10;
        szer++;
    }

    cout << setfill('0');
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX - 1; j++) {
            cout << setw(szer) << t[i][j] << '|';
        }
        cout << setw(szer) << t[i][MAX - 1];
        cout << endl;
    }
}