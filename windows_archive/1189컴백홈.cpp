#include <iostream>

using namespace std;

int sizeX, sizeY, targetLen, res;
bool map[5][5], visited[5][5];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void func(int x, int y, int length) {

    if (length == targetLen) {
        if (x == 0 && y == sizeY - 1)
            res++;
        return;
    }
    if (length > targetLen || (x == 0 && y == sizeY - 1)) return;

    visited[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx == sizeX || ny < 0 || ny == sizeY
            || map[nx][ny] || visited[nx][ny]) continue;
        func(nx, ny, length + 1);
    }
    visited[x][y] = false;

}

int main() {

    cin >> sizeX >> sizeY >> targetLen;
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            char temp; cin >> temp;
            map[i][j] = temp == 'T';
        }
    }

    func(sizeX - 1, 0, 1);

    cout << res;

}