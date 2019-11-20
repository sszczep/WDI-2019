const int N = 8;

//moves(t, t[0][k], k, 0)
bool moves(int tab[N][N], int g, int k, int w) {
    if (k == -1 || k == N) {
        return false;
    }
    if (g > tab[w][k]) {
        return false;
    }
    if (w == N - 1) {
        return true;
    }
    return moves(tab, tab[k][w], k - 1, w + 1) ||
           moves(tab, tab[k][w], k, w + 1) ||
           moves(tab, tab[k][w], k + 1, w + 1);
}