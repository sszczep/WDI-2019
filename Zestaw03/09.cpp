#error jest to bezposredni zapis z zajec WDI z 30.10.2019 - nalezy go uzupelnic o dane testowe/podpiac zrodlo danych z randa (oczywiscie w rozsadnym zakresie)

using namespace std;

int const N = 100;

bool skoki(int t[N]) {
    bool dost[N];
    dost[0] = true;

    for (int i = 1; i < N; i++) {
        dost[i] = false;
    }

    for (int i = 0; i < N; i++) {
        if (dost[i]) {
            int copy = t[i];
            int podzielnik = 2;
            while (copy > 1) {
                if (copy % podzielnik == 0) {
                    if (i + podzielnik < N) {
                        dost[i + podzielnik] = true;
                    }
                    if (i + podzielnik == N - 1) {
                        return true;
                    }
                    while (copy % podzielnik == 0) {
                        copy /= podzielnik;
                    }
                }
                podzielnik++;
            }
        }
    }

    return false;
}

int main() {

}