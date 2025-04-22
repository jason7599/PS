#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int b_height, b_width;
int bucket[300][300];
bool visited[300][300];

const int DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool is_oob(int y, int x) {
    return y < 0 || y >= b_height || x < 0 || x >= b_width;
}

/**
 * bfs해서 테두리 밖으로 넘어가면 거긴 아예 fucked.
 * bfs 돌려서 fucked인게 아니라면, border 중에서 가장 키 작은 애로 다시 시도하기??
 */
int func(int y, int x) {
    queue<pii> q({{y, x}});
    visited[y][x] = 1;

    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> b_width >> b_height;
    for (int y = 0; y < b_height; y++) {
        for (int x = 0; x < b_width; x++) {
            cin >> bucket[y][x];
        }
    }

    int ans = 0;
    for (int y = 1; y < b_height - 1; y++) {
        for (int x = 1; x < b_width - 1; x++) {

        }
    }
    cout << ans << '\n';
}