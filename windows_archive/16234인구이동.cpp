#include <iostream>
#include <queue>

using namespace std;

int mapSize;
int map[50][50];
bool visited[50][50];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
    int L, R;
    cin >> mapSize >> L >> R;

    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            cin >> map[i][j];
        }
    }

    int days = 0;

    while (true) {
        bool deadlock = true;

        for (int i = 0; i < mapSize; i++) {
            for (int j = 0; j < mapSize; j++) {
                if (visited[i][j]) continue;

                queue<pair<int, int>> q; q.push({ i,j });
                queue<pair<int, int>> mergeQ; mergeQ.push({ i,j });

                visited[i][j] = true;

                int sum = map[i][j];
                int count = 1;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || nx == mapSize || ny < 0 || ny == mapSize) continue;
                        if (visited[nx][ny]) continue;

                        int delta = abs(map[x][y] - map[nx][ny]);
                        if (delta < L || delta > R) continue;

                        deadlock = false;
                        q.push({ nx,ny }); mergeQ.push({ nx,ny });
                        visited[nx][ny] = true;
                        sum += map[nx][ny]; count++;
                    }
                }

                int temp = sum / count;
                while (!mergeQ.empty()) {
                    int x = mergeQ.front().first;
                    int y = mergeQ.front().second;
                    map[x][y] = temp;
                    mergeQ.pop();
                }

            }
        }

        if (deadlock) break;

        // cout<<"map=============\n";
        for (int i = 0; i < mapSize; i++) {
            for (int j = 0; j < mapSize; j++) {
                // cout<<map_cpy[i][j]<<' ';
                visited[i][j] = false;
            }
            // cout<<endl;
        }



        days++;
    }

    cout << days;
}