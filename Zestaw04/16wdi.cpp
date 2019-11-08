const int N = 100;

bool wcp(int a) {
    while (a > 0) {
        int c = a % 10;
        if (!(c == 2 || c == 3 || c == 5 || c == 7)) {
            return false;
        }
        a /= 10;
    }
    return true;
}

bool kwp(int t[N][N]) {
    for (int w = 0; w < N; w++) {
        bool zawiera = false;
        for (int k = 0; k < N; k++) {
            if (wcp(t[w][k])) {
                zawiera = true;
                break;
            }
        }
        if (!zawiera) {
            return false;
        }
    }
    return true;
}