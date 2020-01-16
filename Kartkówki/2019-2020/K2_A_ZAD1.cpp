#include <iostream>

const int MAX1 = 1;
const int MAX2 = 2;

int parzystychCyfr(int x) {
    int counter = 0;
    while(x != 0) {
        if((x % 5) % 2 == 0) counter++;
        x /= 5;
    }
    return counter;
}

bool czyPokrywa(int tab1[MAX1][MAX1], int tab2[MAX2][MAX2]) {
    int t1[MAX1][MAX1], t2[MAX2][MAX2];
    for(int i = 0; i < MAX1; i++)
        for(int j = 0; j < MAX1; j++)
            t1[i][j] = parzystychCyfr(tab1[i][j]);
    for(int i = 0; i < MAX2; i++)
        for(int j = 0; j < MAX2; j++)
            t2[i][j] = parzystychCyfr(tab2[i][j]);

    for(int t1_posY = 1 - MAX1; t1_posY < MAX2; t1_posY++) {
        for(int t1_posX = 1 - MAX1; t1_posX < MAX2; t1_posX++) {
            int suma = 0;
            int pokryte = 0;
            for(int t1_idxX = 0; t1_idxX < MAX1; t1_idxX++) {
                for(int t1_idxY = 0; t1_idxY < MAX1; t1_idxY++) {
                    int t2_idxX = t1_idxX + t1_posX;
                    int t2_idxY = t1_idxY + t1_posY;

                    if(
                        (t2_idxX >= 0 && t2_idxX < MAX2)
                        && (t2_idxY >= 0 && t2_idxY < MAX2)
                    ) {
                        suma++;
                        if(t1[t1_idxX][t1_idxY] == t2[t2_idxX][t2_idxY]) {
                            pokryte++;
                        }
                    }
                }
            }

            if(pokryte * 100 >= suma * 33) return true;
        }
    }
    
    return false;
}

int main() {
    int tab1[MAX1][MAX1] = { { 4 } };
    int tab2[MAX2][MAX2] = { { 9, 7 }, { 8, 5 } };
    std::cout << czyPokrywa(tab1, tab2);
}
