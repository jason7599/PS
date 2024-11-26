#include <iostream>
#include <cstring>
#include <queue>

#define INF 987654321

using namespace std;

int labSize, virusCount, disinfectedTiles, lab[50][50], minTime = INF;
bool visited[50][50];
vector<pair<int, int>> placeableCoords;
vector<pair<int, int>> virusCoords;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int spreadViruses() {

    if (!disinfectedTiles) return 0;

    int remaining = disinfectedTiles;
    int time = 0;
    queue<pair<int, int>> spreadQ;

    for (auto virusCoord : virusCoords) {
        spreadQ.push(virusCoord);
        visited[virusCoord.first][virusCoord.second] = true;
    }

    while (!spreadQ.empty()) {
        time++;
        int t = spreadQ.size();
        while (t--) {
            int x = spreadQ.front().first;
            int y = spreadQ.front().second;
            spreadQ.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx == labSize || ny < 0 || ny == labSize
                    || visited[nx][ny] || lab[nx][ny] == 1) continue;

                visited[nx][ny] = true;

                if (lab[nx][ny] != 2)
                    if (!(--remaining)) return time;

                spreadQ.push({ nx, ny });
            }

        }

    }

    return INF;

}

void placeViruses(int coordIndex = 0) {

    // 배치 성공
    if (virusCoords.size() == virusCount) {
        int res = spreadViruses();
        if (minTime > res) minTime = res;
        memset(visited, 0, sizeof(visited));
        return;
    }

    // 불가능
    if (virusCount - virusCoords.size() > placeableCoords.size() - coordIndex) {
        return;
    }

    // 배치하고 다음으로
    virusCoords.push_back(placeableCoords[coordIndex]);
    placeViruses(coordIndex + 1);
    virusCoords.pop_back();

    // 배치 안하고 다음으로
    placeViruses(coordIndex + 1);

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> labSize >> virusCount;

    for (int i = 0; i < labSize; i++) {
        for (int j = 0; j < labSize; j++) {
            int temp; cin >> temp;
            if (temp) { // 벽 혹은 바이러스 설치 가능한 위치
                if (temp == 2) // placeable coords
                    placeableCoords.push_back({ i, j });
            }
            else disinfectedTiles++;
            lab[i][j] = temp;
        }
    }

    placeViruses();

    if (minTime != INF) cout << minTime;
    else cout << -1;


}