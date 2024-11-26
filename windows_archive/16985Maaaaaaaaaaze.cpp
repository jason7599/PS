#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

#define INF 987654321
#define MAZE_SIZE 5

bool maze[MAZE_SIZE][MAZE_SIZE][MAZE_SIZE];
bool visited[MAZE_SIZE][MAZE_SIZE][MAZE_SIZE];
bool placed[MAZE_SIZE];
int rotation[MAZE_SIZE], layer[MAZE_SIZE];
int leastMoves = INF;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int dl[] = { 1, -1 };

void shuffleMazes(int layerIndex = 0);
pair<int, int> rotateCoordinates(int row, int col, int rotate);
int solveMaze();

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int k = 0; k < MAZE_SIZE; k++)
        for (int i = 0; i < MAZE_SIZE; i++)
            for (int j = 0; j < MAZE_SIZE; j++)
                cin >> maze[k][i][j];

    shuffleMazes();

    if (leastMoves == INF) cout << -1;
    else cout << leastMoves;

}

// probably can optimize this quite a lot
// ex: rotation(0,0,0,0,0) == rotation(1,1,1,1,1)
// so far, 122880 possibilities
void shuffleMazes(int layerIndex) {

    if (layerIndex == MAZE_SIZE) {
        int moves = solveMaze();
        if (moves < leastMoves) leastMoves = moves;
        memset(visited, false, sizeof(visited));
        return;
    }

    for (int mazeIndex = 0; mazeIndex < MAZE_SIZE; mazeIndex++)
    {
        if (placed[mazeIndex]) continue;

        placed[mazeIndex] = true;
        layer[layerIndex] = mazeIndex;

        for (int rotate = 0; rotate < 4; rotate++) {
            rotation[mazeIndex] = rotate;
            shuffleMazes(layerIndex + 1);
        }

        placed[mazeIndex] = false;
    }

}

/*
row, col을 rotate * 90도 시계방향으로 회전시켰을때 좌표.
rotate에 음수 값을 주면 역함수처럼 사용할 수 있음.
*/
pair<int, int> rotateCoordinates(int row, int col, int rotate) {
    rotate = (rotate + 4) % 4;
    if (rotate == 0) return { row, col };
    if (rotate == 1) return { col, MAZE_SIZE - 1 - row };
    if (rotate == 2) return { MAZE_SIZE - 1 - row, MAZE_SIZE - 1 - col };
    else return { MAZE_SIZE - 1 - col, row };
}

int solveMaze()
{
    int layerIndex = 0; // 층을 쌓은 순서.
    // ex) layer[0]은 위 shuffleMazes을 통해 정해진 첫째 층의 인덱스를 뜻함
    // ex) 두번째 층에 오는 미로: maze[layer[1]][x][y]

    // 회전된 미로의 [0][0] 좌표에 대응하는 원본 미로의 좌표
    pair<int, int> startCoord = rotateCoordinates(0, 0, -rotation[layerIndex]);
    int x = startCoord.first;
    int y = startCoord.second;

    if (!maze[layer[layerIndex]][x][y]) return INF;

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(layerIndex, x, y));
    visited[layerIndex][x][y] = true;
    // *** visited나 push는 layerIndex 기준으로 하는게 나아 보임.
    // 실제 층 인덱스인 z로 push한다면, 예를 들어 4를 push 한다면, 
    // 4의 위나 아래층의 인덱스를 구할 때 layer 배열을 선형탐색해야 하잖아

    // 회전된 미로의 [4][4]에 대응하는 원본 미로의 좌표. 실제 목표지
    pair<int, int> goalCoord = rotateCoordinates(MAZE_SIZE - 1, MAZE_SIZE - 1, -rotation[MAZE_SIZE - 1]);
    int goalX = goalCoord.first;
    int goalY = goalCoord.second;

    int moves = 0;

    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            layerIndex = get<0>(q.front());
            x = get<1>(q.front());
            y = get<2>(q.front());

            if (x == goalX && y == goalY && layerIndex == MAZE_SIZE - 1) return moves;

            q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx == MAZE_SIZE || ny < 0 || ny == MAZE_SIZE) continue;

                // maze 체크만 실제 층 인덱스로
                if (visited[layerIndex][nx][ny] || !maze[layer[layerIndex]][nx][ny]) continue;

                q.push(make_tuple(layerIndex, nx, ny));
                visited[layerIndex][nx][ny] = true;
            }

            int curRotation = rotation[layerIndex];

            for (int l = 0; l < 2; l++)
            {
                int nLayer = layerIndex + dl[l];

                if (nLayer < 0 || nLayer == MAZE_SIZE) continue;

                int nRotation = rotation[nLayer];

                // 회전된 현재 층에서, 회전된 다음 층으로 갔을 때 도달할 좌표와 대응하는 실제 미로의 좌표
                pair<int, int> newCoords = rotateCoordinates(x, y, curRotation - nRotation);

                int nx = newCoords.first;
                int ny = newCoords.second;

                if (visited[nLayer][nx][ny] || !maze[layer[nLayer]][nx][ny]) continue;

                q.push(make_tuple(nLayer, nx, ny));
                visited[nLayer][nx][ny] = true;

            }
        }
        moves++;
    }

    return INF;
}

