#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int sizeX, sizeY, greenCount, redCount, maxFlowers;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int greenMap[50][50], redMap[50][50];
bool garden[50][50];
vector<pair<int, int>> spotsAvailable;
vector<pair<int, int>> greens;
vector<pair<int, int>> reds;


int bloom() {

    queue<pair<int, int>> greenQ;
    queue<pair<int, int>> redQ;

    for (auto g : greens) {
        greenQ.push(g); // 1: visited
        greenMap[g.first][g.second] = 1;
    }

    for (auto r : reds) {
        redQ.push(r);
        redMap[r.first][r.second] = 1;
    }

    int flowers = 0;
    int time = 1; // not exactly time. starts from 1

    while (!greenQ.empty() || !redQ.empty()) {

        time++;

        int gSize = greenQ.size();

        while (gSize--) {

            int x = greenQ.front().first;
            int y = greenQ.front().second;
            greenQ.pop();

            if (greenMap[x][y] == -1) continue;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx == sizeX || ny < 0 || ny == sizeY
                    || !garden[nx][ny] || greenMap[nx][ny] || redMap[nx][ny]) continue;

                greenMap[nx][ny] = time;
                greenQ.push({ nx, ny });
            }
        }

        int rSize = redQ.size();

        while (rSize--) {

            int x = redQ.front().first;
            int y = redQ.front().second;
            redQ.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx == sizeX || ny < 0 || ny == sizeY
                    || !garden[nx][ny] || redMap[nx][ny]) continue;

                if (greenMap[nx][ny]) {
                    if (greenMap[nx][ny] == time) {
                        flowers++;
                        greenMap[nx][ny] = -1;
                    }
                    continue;
                }

                redMap[nx][ny] = time;
                redQ.push({ nx, ny });
            }
        }
    }

    memset(greenMap, 0, sizeof(greenMap));
    memset(redMap, 0, sizeof(redMap));

    return flowers;

}

void placeFluids(int spotIndex = 0) {

    if (spotsAvailable.size() - spotIndex < greenCount + redCount - greens.size() - reds.size()) return;

    if (greens.size() == greenCount && reds.size() == redCount) {
        int res = bloom();
        if (res > maxFlowers) {
            maxFlowers = res;
        }
        return;
    }

    placeFluids(spotIndex + 1); // without placing any

    if (greens.size() != greenCount) { // place green
        greens.push_back(spotsAvailable[spotIndex]);
        placeFluids(spotIndex + 1);
        greens.pop_back();
    }

    if (reds.size() != redCount) { // place red
        reds.push_back(spotsAvailable[spotIndex]);
        placeFluids(spotIndex + 1);
        reds.pop_back();
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> sizeX >> sizeY >> greenCount >> redCount;

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            int temp; cin >> temp;
            if (temp == 2) spotsAvailable.push_back({ i, j });
            garden[i][j] = temp;
        }
    }

    placeFluids();

    cout << maxFlowers;


}