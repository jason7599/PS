#include <iostream>

using namespace std;

int corridorSize;
char corridor[6][6];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool isSafe() {

    for (int x = 0; x < corridorSize; x++) {
        for (int y = 0; y < corridorSize; y++) {
            if (corridor[x][y] != 'T') continue;
            for (int d = 0; d < 4; d++) {
                for (int range = 1; ; range++) {
                    int nx = x + dx[d] * range;
                    int ny = y + dy[d] * range;
                    if (nx < 0 || nx == corridorSize || ny < 0 || ny == corridorSize
                        || corridor[nx][ny] == 'O') break;
                    if (corridor[nx][ny] == 'S') return false;
                }
            }
        }
    }
    return true;

}

bool placeObstacles(int x = 0, int y = 0, int placed = 0) {

    if (placed == 3) return isSafe();

    if (y == corridorSize) { y = 0; x++; }
    if (x == corridorSize) return false;

    if (placeObstacles(x, y + 1, placed)) return true;

    if (corridor[x][y] == 'X') {
        corridor[x][y] = 'O';
        if (placeObstacles(x, y + 1, placed + 1)) return true;
        corridor[x][y] = 'X';
    }

    return false;

}

int main() {

    cin >> corridorSize;

    for (int i = 0; i < corridorSize; i++)
        for (int j = 0; j < corridorSize; j++)
            cin >> corridor[i][j];

    if (placeObstacles()) cout << "YES";
    else cout << "NO";


}