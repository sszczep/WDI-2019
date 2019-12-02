const int N = 8;

bool pierwsza(int n);

bool da_sie(int t[N][N]) {
    const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i]; //x drugiego skoczka
                int ny = y + dy[i]; //y drugiego skoczka
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (pierwsza(t[x][y] + t[nx][ny])) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}