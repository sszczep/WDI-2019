#include <iostream>
using namespace std;

const int N = 10;

//odwazniki(t, 0, do_odwazenia);
bool odwazniki(int t[N], int odwaznik, int do_odwazenia) {
    if (do_odwazenia == 0) {
        return true;
    }
    if (do_odwazenia < 0) {
        return false;
    }
    if (odwaznik == N) {
        return false;
    }
    return (odwazniki(t, odwaznik + 1, do_odwazenia - t[odwaznik]) || 
            odwazniki(t, odwaznik + 1, do_odwazenia));
}

int main() {
    //przyklad uzycia:
    int t[] = {1, 5, 5, 10, 20, 3, 3, 7, 8, 5};
    int do_odwazenia;
    cin >> do_odwazenia;
    cout << (odwazniki(t, 0, do_odwazenia) ? "da sie" : "nie da sie");
}