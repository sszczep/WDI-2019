//czy liczba jest iloczynem 2 liczb pierwszych?
bool spr(int n) {
    int lim = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            lim++;
            if (lim > 2) {
                return false;
            }
            n /= i;
        }
    }
    if (n > 1) {
        lim++;
    }
    return lim == 2;
}