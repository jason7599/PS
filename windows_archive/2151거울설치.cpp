#include <iostream>
#include <queue>

#define INF 987654321
#define ppp pair<pair<int, int>, pair<int, int>>

using namespace std;

int roomSize, targetX, targetY, dist[50][50];
// up, right, down, left
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char room[50][50];

bool chck(int x, int y) {
    return !(x < 0 || x == roomSize || y < 0 || y == roomSize || room[x][y] == '*');
}

int dijkstra(int startX, int startY) {

    dist[startX][startY] = true;
    priority_queue<ppp, vector<ppp>, greater<ppp>> pq;

    for (int d = 0; d < 4; d++) {
        int nx = startX, ny = startY;
        while (true) {
            nx += dx[d];
            ny += dy[d];
            if (!chck(nx, ny)) break;
            if (room[nx][ny] == '!' || room[nx][ny] == '#') {
                dist[nx][ny] = 0;
                pq.push({{0, d}, {nx, ny}});
            }
        }
    }

    while (!pq.empty()) {

        int dst = pq.top().first.first;
        int dir = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for (int k = 0; k < 2; k++) {
            int nx = x, ny = y;
            int nDir = (dir + (k ? 1 : 3)) % 4;
            while (true) {
                nx += dx[nDir];
                ny += dy[nDir];
                if (!chck(nx, ny)) break;
                if ((room[nx][ny] == '!' || room[nx][ny] == '#') && dst + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dst + 1;
                    pq.push({{dst + 1, nDir}, {nx, ny}});
                }
            }
        }
        
    }

    return dist[targetX][targetY];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> roomSize;

    int startX = -1, startY;
    for (int i = 0; i < roomSize; i++) {
        for (int j = 0; j < roomSize; j++) {
            char temp; cin >> temp;
            room[i][j] = temp;
            if (temp == '#') {
                if (startX == -1) {
                    startX = i;
                    startY = j;
                }
                else {
                    targetX = i;
                    targetY = j;
                }
            }
            dist[i][j] = INF;
        }
    }

    cout << dijkstra(startX, startY);

}