#include <iostream>

using namespace std;

int boardSize, board[100][100];
long long memo[100][100];

long long jump(int x = 0, int y = 0) {

    if (x >= boardSize || y >= boardSize) return 0;

    if (memo[x][y] != -1) return memo[x][y];

    if (x == boardSize - 1 && y == boardSize - 1) {
        memo[x][y] = 1;
        return 1;
    }

    int val = board[x][y];
    long long res;
    if (!val) res = 0;
    else res = jump(x + val, y) + jump(x, y + val);
    memo[x][y] = res;
    return res;
}

int main() {

    cin >> boardSize;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cin >> board[i][j];
            memo[i][j] = -1;
        }
    }

    cout << jump();

}