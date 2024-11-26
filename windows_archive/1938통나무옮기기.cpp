#include <iostream>
#include <queue>

using namespace std;

int mapSize, eX, eY, eRotation;
char map[50][50];
bool visited[50][50][2];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool canMoveTo(int x, int y, int rotation = -1) {
    if (x < 0 || x == mapSize || y < 0 || y == mapSize || map[x][y] == '1') return false;
    if (rotation != -1) {
        if (visited[x][y][rotation]) return false;
        if (rotation) return canMoveTo(x - 1, y) && canMoveTo(x + 1, y);// 세로
        else return canMoveTo(x, y - 1) && canMoveTo(x, y + 1); // 가로
    }
    return true;
}

bool canSpin(int x, int y) {
    return canMoveTo(x - 1, y - 1) && canMoveTo(x - 1, y) && canMoveTo(x - 1, y + 1)
        && canMoveTo(x, y - 1) && canMoveTo(x, y + 1)
        && canMoveTo(x + 1, y - 1) && canMoveTo(x + 1, y) && canMoveTo(x + 1, y + 1);
}

int bfs(int x, int y, int rotation) {

    queue<pair<int, pair<int, int>>> q;
    q.push({ rotation, {x, y} });
    visited[x][y][rotation] = true;
    int time = 0;

    while (!q.empty()) {
        time++;
        int qSize = q.size();
        while (qSize--) {
            rotation = q.front().first;
            x = q.front().second.first;
            y = q.front().second.second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (canMoveTo(nx, ny, rotation)) {
                    if (nx == eX && ny == eY && rotation == eRotation) return time;
                    q.push({ rotation, {nx, ny} });
                    visited[nx][ny][rotation] = true;
                }
            }

            int nRotation = (rotation + 1) % 2;
            if (!visited[x][y][nRotation] && canSpin(x, y)) {
                if (x == eX && y == eY && nRotation == eRotation) return time;
                q.push({ nRotation, {x, y} });
                visited[x][y][nRotation] = true;
            }
        }
    }
    return 0;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> mapSize;

    int x, y;
    int rotation = 0; // 0: 가로, 1: 세로

    int bCount = 0, eCount = 0;
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            char temp; cin >> temp;
            if (temp == 'B' && ++bCount == 2) x = i, y = j;
            else if (temp == 'E' && ++eCount == 2) eX = i, eY = j;
            map[i][j] = temp;
        }
    }

    if (x + 1 != mapSize && map[x + 1][y] == 'B') rotation = 1;
    if (eX + 1 != mapSize && map[eX + 1][eY] == 'E') eRotation = 1;

    // cout << "\nB: " << x << ", " << y << ", rotation: " << rotation << '\n';
    // cout << "E: " << eX << ", " << eY << ", rotation: " << eRotation << '\n';

    cout << bfs(x, y, rotation);


}