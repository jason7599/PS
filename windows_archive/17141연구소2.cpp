#include <iostream>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;

int labSize, virusCount;
int lab[50][50];
int minTime = INF;
int remaining;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool visited[50][50];
vector<pair<int, int>> spotsAvailable;
vector<pair<int, int>> viruses;

int spreadVirus();
void placeViruses(int index = 0, int placed = 0);
// bool inViruses(int x, int y);
// void printLab();

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> labSize >> virusCount;

    for (int i = 0; i < labSize; i++) {
        for (int j = 0; j < labSize; j++) {
            int temp; cin >> temp;
            lab[i][j] = temp;
            if (temp != 1) {
                if (temp == 2)
                    spotsAvailable.push_back({ i, j });
                remaining++;
            }
        }
    }

    placeViruses();

    if (minTime != 987654321) cout << minTime;
    else cout << -1;

}

void placeViruses(int index, int placed) {

    if (index == spotsAvailable.size()) {
        if (placed == virusCount) {
            int temp = spreadVirus();
            if (temp < minTime) minTime = temp;
            memset(visited, false, sizeof(visited));
        }
        return;
    }
    // without placing virus
    placeViruses(index + 1, placed);
    // place virus
    viruses.push_back(spotsAvailable[index]);
    placeViruses(index + 1, placed + 1);
    viruses.pop_back();

}

int spreadVirus() {

    int time = 0;
    int remainingCpy = remaining;
    queue<pair<int, int>> spread;
    int t = viruses.size();

    for (int i = 0; i < t; i++) {
        int x = viruses[i].first;
        int y = viruses[i].second;
        spread.push({ x, y });
        visited[x][y] = true;
        remainingCpy--;
    }

    if (!remainingCpy) return 0;

    while (t) {

        time++;

        while (t--) {

            int x = spread.front().first;
            int y = spread.front().second;
            spread.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx == labSize || ny < 0 || ny == labSize
                    || visited[nx][ny] || lab[nx][ny] == 1) continue;

                spread.push({ nx,ny });
                visited[nx][ny] = true;
                if (!(--remainingCpy)) return time;
            }
        }

        t = spread.size();
    }

    return INF;
}

// bool inViruses(int x, int y) {
//     for (pair<int, int> p : viruses) {
//         if (p.first == x && p.second == y)
//             return true;
//     }
//     return false;
// }

// void printLab() {
//     cout << "===========================\n";
//     for (int i = 0; i < labSize; i++) {
//         for (int j = 0; j < labSize; j++) {
//             if (inViruses(i, j)) cout << '*';
//             else cout << lab[i][j];
//         }
//         cout << '\n';
//     }
//     cout << "===========================\n";
// }