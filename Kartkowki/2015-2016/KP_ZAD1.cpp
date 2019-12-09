const int N = 10;

int t[N][N];

bool jest_w_fib(int sA, int sB, int sC) {
    int a = 1;
    int b = 1;
    int c;
    while (c <= sC) {
        c = a + b;
        if (sA == a && sB == b) {
            return true;
        }
        a = b;
        b = c;
    }
    return false;
}

int podciag() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 2; j++) {
            if (t[i][j] < t[i][j + 1] && t[i][j] + t[i][j + 1] == t[i][j + 2]) {
                if (jest_w_fib(t[i][j], t[i][j + 1], t[i][j + 2])) {
                    return i;
                }
            }
        }
    }
}
