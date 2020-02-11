#include <iostream>

const int N = 4;

bool gen(int t[], int target, int r1 = -1, int r2 = -1, int r3 = -1) {
    if(r1 == -1) {
        for(int i = 0; i < N; i++) {
            if(gen(t, target, i, r2, r3)) return true;
        }
    } else if(r2 == -1) {
        for(int i = 0; i < N; i++) {
            if(i == r1) continue;
            if(gen(t, target, r1, i, r3)) return true;
        }
    } else if(r3 == -1) {
        for(int i = 0; i < N; i++) {
            if(i == r1 || i == r2) continue;
            if(gen(t, target, r1, r2, i)) return true;
        }
    } else {
        // Takie som wzorki hehe
        return t[r1] + t[r2] + t[r3] == target
            || ((t[r1] + t[r2]) * t[r3]) / (t[r1] + t[r2] + t[r3]) == target
            || (t[r1] * t[r2]) / (t[r1] + t[r2]) + t[r3] == target
            || (t[r1] * t[r2] * t[r3]) / (t[r1] * t[r2] + t[r2] * t[r3] + t[r1] * t[r3]) == target;
    }
}

int main() {
    int t[N] = { 2, 2, 3, 7 };
    std::cout << gen(t, 9);
}
