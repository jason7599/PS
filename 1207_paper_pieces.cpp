#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Piece {
    int h, w;
    int start_x = -1;
    vector<pii> spots;
};

int b_size;
int board[10][10];
Piece pieces[5];

void remove(int pi, int y, int x, int i = -1) {
    const Piece& p = pieces[pi];
    if (i == -1) {
        i = p.spots.size();
    }
    while (i--) {
        const auto& [m, n] = p.spots[i];
        board[y + m][x + n] = 0;
    }
}

bool try_place(int pi, int y, int x) {
    const Piece& p = pieces[pi];
    if (y + p.h > b_size || x < 0 || x + p.w > b_size) {
        return 0;
    }

    for (int i = 0; i < p.spots.size(); i++) {
        int m = y + p.spots[i].first;
        int n = x + p.spots[i].second;

        if (board[m][n]) {
            remove(pi, y, x, i);
            return 0;
        }

        board[m][n] = 1 + pi;
    }
    return 1;
}

bool solve(int i = 0, int used_mask = 0) {
    if (used_mask == (1 << 5) - 1) {
        return 1;
    }

    int y = i / b_size;
    int x = i % b_size;

    if (board[y][x]) {
        return solve(i + 1, used_mask);
    }

    for (int pi = 0; pi < 5; pi++) {
        if (!(used_mask & (1 << pi))) {
            int xx = x - pieces[pi].start_x;
            if (try_place(pi, y, xx)) {
                if (solve(i + 1, used_mask | (1 << pi))) {
                    return 1;
                }
                remove(pi, y, xx);
            }
        }
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> b_size;
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        Piece& p = pieces[i];
        cin >> p.h >> p.w;
        for (int y = 0; y < p.h; y++) {
            for (int x = 0; x < p.w; x++) {
                char c;
                cin >> c;
                if (c == '#') {
                    p.spots.push_back({y, x});
                    if (p.start_x == -1) {
                        p.start_x = x;
                    }
                    cnt++;
                }
            }
        }
    }

    if (cnt != b_size * b_size || !solve()) {
        cout << "gg\n";
        return 0;
    }

    for (int y = 0; y < b_size; y++) {
        for (int x = 0; x < b_size; x++) {
            cout << board[y][x];
        }
        cout << '\n';
    }
}