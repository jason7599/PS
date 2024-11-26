#include <iostream>
#include <queue>

using namespace std;

int toyCount;
vector<pair<int, int>> req[101];
int reqCount[101][101];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> toyCount;
    int reqCnt;
    cin >> reqCnt;

    while (reqCnt--) {
        int x, y, k;
        cin >> x >> y >> k;
        req[x].push_back({ y, k });
    }

    for (int toy = 1; toy <= toyCount; toy++) {
        if (req[toy].empty()) reqCount[toy][toy] = 1;
        else {
            for (auto a : req[toy]) {
                int subToy = a.first;
                int count = a.second;
                for (int i = 1; i <= toyCount; i++) {
                    reqCount[toy][i] = reqCount[subToy][i] * count;
                }
            }
        }
    }

    for (int i = 1; i <= toyCount; i++) {
        if (reqCount[toyCount][i]) {
            cout << i << ' ' << reqCount[toyCount][i] << '\n';
        }
    }


}