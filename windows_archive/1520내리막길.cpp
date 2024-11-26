#include <iostream>

using namespace std;

int sizeX, sizeY;
int terrain[500][500];
int dp[500][500];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


// x,y에서 끝까지 갈 수 있는 경우의 수
int dfs(int x = 0, int y = 0) {

    // 도착
    if (x == sizeX - 1 && y == sizeY - 1) return 1;

    // memoization
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0; // visited. to differentiate between coords not memoed
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx == sizeX || ny < 0 || ny == sizeY
            || terrain[x][y] <= terrain[nx][ny]) continue;

        dp[x][y] += dfs(nx, ny); //memo
    }

    return dp[x][y];
}

int main() {

    cin >> sizeX >> sizeY;

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            cin >> terrain[i][j];
            dp[i][j] = -1; // not yet visited
            // == not yet calculated
        }
    }

    cout << dfs();

}