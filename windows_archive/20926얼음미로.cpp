#include <iostream>
#include <queue>

#define pip pair<int,pair<int,int>>
#define INF 987654321

using namespace std;

int sizeX, sizeY, dist[500][500], terraX, terraY, exitX, exitY;
char maze[500][500];
int dx[] = { 1, 0, -1, 0 }; // 아래, 오른쪽, 위, 왼쪽
int dy[] = { 0, 1, 0, -1 };

pip slide(int x, int y, int dir) {

    int nx = x, ny = y, d = 0;

    while (true) {
        nx += dx[dir];
        ny += dy[dir];

        if (nx < 0 || nx == sizeX || ny < 0 || ny == sizeY
            || maze[nx][ny] == 'H') return { -1, {-1, -1} };

        if (maze[nx][ny] == 'E') return { d, {nx, ny} };
        if (maze[nx][ny] == 'R') return { d, { nx - dx[dir], ny - dy[dir]} };

        d += maze[nx][ny] - '0';
    }

}

void dijkstra() {

    priority_queue<pip, vector<pip>, greater<pip>> pq;
    pq.push({ 0, {terraX, terraY} });

    while (!pq.empty()) {

        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int d = pq.top().first;
        pq.pop();

        if (x == exitX && y == exitY) continue;

        for (int dir = 0; dir < 4; dir++) {

            pip n = slide(x, y, dir);
            if (n.first == -1) continue;

            int nx = n.second.first;
            int ny = n.second.second;
            int nd = n.first + d;

            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                pq.push({ nd, {nx, ny} });
            }
        }
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> sizeY >> sizeX;

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            char temp; cin >> temp;
            if (temp == 'T') {
                dist[i][j] = 0;
                maze[i][j] = '0';
                terraX = i;
                terraY = j;
            }
            else {
                if (temp == 'E') {
                    exitX = i;
                    exitY = j;
                }
                dist[i][j] = INF;
                maze[i][j] = temp;
            }
        }
    }

    dijkstra();

    if (dist[exitX][exitY] == INF) cout << -1;
    else cout << dist[exitX][exitY];

}