//"wyszukaj pary dajace zadany iloczyn"
const int N = 100;
int t[N];

//counting sort?
int counter(int t[], int size, int prod) {
    int cnt = 0;
    for (int i = 0; i < size - 1; i++) {
        if (prod % t[i] == 0) {
            for (int j = i + 1; j < size; j++) {
                if (t[i] * t[j] == prod) {
                    cnt++;
                }
            }

        }
    }
    return cnt;
}

//kwadrat; linearyzacja
int counter2(int t[N][N], int prod) {
    int cnt = 0;
    for (int i = 0; i < N * N - 1; i++) {
        if (prod % t[i / N][i % N] == 0) {
            for (int j = i + 1; j < N * N; j++) {
                if (t[i / N][i % N] * t[j / N][j % N] == prod) {
                    cnt++;
                }
            }

        }
    }
    return cnt;
}