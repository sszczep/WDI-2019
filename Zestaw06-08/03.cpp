#include <iostream>
using namespace std;

const int N = 100;

bool odwazniki(int t[N], int odwaznik, int do_odwazenia) {
    if (do_odwazenia == 0) {
        return true;
    }
    if (odwaznik == N) {
        return false;
    }
    if (odwazniki(t, odwaznik + 1, do_odwazenia - t[odwaznik])) {
        cout << 'L' << t[odwaznik] << endl;
        return true;
    }
    if (odwazniki(t, odwaznik + 1, do_odwazenia + t[odwaznik])) {
        cout << 'P' << t[odwaznik] << endl;
        return true;
    }
    return odwazniki(t, odwaznik + 1, do_odwazenia);
}