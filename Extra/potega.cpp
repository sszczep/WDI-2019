//czy liczba jest co najmniej drugą potęgą dowolnej liczby naturalnej?
bool pot(int a) {
    if (a == 1) {
        return true;
    }
    for (int i = 2; i * i < a; i++) {
        if (a % i == 0) {
            int tmp = i;
            while (tmp < a) {
                tmp *= i;
            }
            if (tmp == a) {
                return true;
            }
        }
    }
    return false;
}