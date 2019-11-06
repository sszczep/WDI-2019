const int N = 10;

void spirala(int t[N][N]) {
    int a = 1;
    int s = 0, k = N - 1;

    for (int a = 1, s = 0, k = N - 1; s <= k; s++, k--) {
        //sprobowac zwinac w 1 petle zamiast 3 ponizej
        if (s == k) {
            t[s][k] = a;
        }
        for (int i = s; i < k; i++) {
            t[s][i] = a++;
            t[i][k] = a + k + s - 1;
        }
        for (int i = k; i > s; i--) t[k][i] = a++;
        for (int i = k; i < s; i--) t[i][s] = a++;
    }
    s++;
    k--;
}