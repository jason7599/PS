#include <iostream>

using namespace std;

int mapSize, dp[3][16][16], ans;
bool map[16][16];

bool chck(int x, int y) {
    return !(x < 0 || x == mapSize || y < 0 || y == mapSize || map[x][y]);
}
bool finish(int x, int y) {
    return x == mapSize - 1 && y == mapSize - 1;
}

// dir: 0 = 가로, 1 = 세로, 2 = 대각
int func(int x = 0, int y = 1, int dir = 0) {

    int& res = dp[dir][x][y];

    if (res != -1) return res;

    if (!dir) { // 가로
        if (chck(x, y + 1)) {
            if (finish(x, y + 1))
                return res = 1;
            res += func(x, y + 1, 0);
            // if (chck)
        }
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> mapSize;

    for (int i = 0; i < mapSize; i++)  {
        for (int j = 0; j < mapSize; j++) {
            cin >> map[i][j];
            for (int k = 0; k < 3; k++)
                dp[k][i][j] = -1;
        }
    }



}