#include <iostream>
#include <queue>

#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int R, C, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool bomb[200][200];

void explode(vector<pair<int, int>> bombCoords) {

    

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> R >> C >> N;

    vector<pair<int, int>> bombCoords;
    FOR(i, R) FOR(j, C) {
        char temp; cin >> temp;
        if (temp == 'O') {
            bombCoords.push_back({i, j});
            bomb[i][j] = true;
        }
    }



}