const int N = 10;

bool pierwsza(int n);

//podz(t, 0);
bool podz(int tab[N], int p) {
    if (p == N) {
        return true;
    }
    int a = 0;
    for (int i = p; i < N and i < 30; i++) {
        a = a * 2 + tab[i];
        if (pierwsza(a) and podz(tab, i + 1)) {
            return true;
        }
    }
    return false;
}