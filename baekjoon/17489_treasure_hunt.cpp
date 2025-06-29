#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const pii MOVES[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int g_h, g_w, s_l;
char grid[101][101];
bool vis[101][101];
string str;

/**
 * str 다 커버했을때만 한번에 다 방문처리.
 * 차피 str에 중복 없으니까.
 * 그럼 다음 글자랑 일치하면서 방문처리 되어있으면 무조건 루프인거고 그럼 바로 -1.
 */
//

int max_iter;
pii ans_pos;

bool solve(int y, int x, int idx) {
    vis[y][x] = 1;


}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> g_h >> g_w >> s_l >> str;

    for (int y = 1; y <= g_h; y++) {
        for (int x = 1; x <= g_w; x++) {
            cin >> grid[y][x];
        }
    }
}