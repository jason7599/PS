#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
#define REP(n) FOR(i, n)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; }
template<typename T> void input(T& t) { cin >> t; }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...);}

struct Sticker {
    pii pos;
    int size;
};

bool grid[10][10];
int n_stickers;
Sticker stickers[25];
int used_cnts[5];

int ans = 26;

bool is_covered(int y, int x, const Sticker& s) {
    return s.pos.first <= y && y < s.pos.first + s.size
        && s.pos.second <= x && x < s.pos.second + s.size;
}

bool is_covered(int y, int x) {
    if (!grid[y][x]) {
        return 1;
    }
    FOR(i, n_stickers) {
        if (is_covered(y, x, stickers[i])) {
            return 1;
        }
    }
    return 0;
}

void f(int pos) {
    if (pos == 10 * 10) {
        ans = min(ans, n_stickers);
        return;
    }

    int y = pos / 10;
    int x = pos % 10;

    if (is_covered(y, x)) {
        return f(pos + 1);
    }

    RANGE(size, 1, 5) {
        if (y + size > 10 || x + size > 10) {
        brk:
            break;
        }
        
        RANGE(yy, y, y + size - 1) {
            if (is_covered(yy, x + size - 1)) {
                goto brk;
            }
        }
        RANGE(xx, x, x + size - 2) {
            if (is_covered(y + size - 1, xx)) {
                goto brk;
            }
        }
        
        if (used_cnts[size - 1] == 5) {
            continue;
        }
        
        stickers[n_stickers++] = Sticker{{y, x}, size};
        used_cnts[size - 1]++;

        f(pos + 1);

        n_stickers--;
        used_cnts[size - 1]--;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    FOR(y, 10) {
        FOR(x, 10) {
            input(grid[y][x]);
        }
    }

    f(0);

    print(ans == 26 ? -1 : ans);
}