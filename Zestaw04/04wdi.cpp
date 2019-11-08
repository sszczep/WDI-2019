const int MAX = 10;

void maxil(int t[MAX][MAX], int &w, int &k) {
    int sk, sw;
    int maxsk = 0, minsw = __INT_MAX__;
    for (int i = 0; i < MAX; i++) {
        sk = 0;
        sw = 0;
        for (int j = 0; j < MAX; j++) {
            sk += t[j][i];
            if (sk > maxsk) {
                maxsk = sk;
                k = i;
            }
            if (sw < minsw) {
                minsw = sw;
                w = i;
            }
        }
    }
}