const int N = 100;

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