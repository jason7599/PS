#include <bits/stdc++.h>
using namespace std;

int grid[1002][1002];
int sizes[100];

void place_paper(int y, int x, int w, int h, int i) {
    sizes[i] = w * h;
    for (int ny = y; ny < y + w; ny++) {
        for (int nx = x; nx < x + h; nx++) {
            if (grid[ny][nx]) {
                sizes[grid[ny][nx] - 1]--;
            }
            grid[ny][nx] = i + 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_papers;
    cin >> n_papers;
    for (int i = 0; i < n_papers; i++) {
        int y, x, w, h;
        cin >> y >> x >> w >> h;
        place_paper(y, x, w, h, i);
    }

    for (int i = 0; i < n_papers; i++) {
        cout << sizes[i] << '\n';
    }
}
