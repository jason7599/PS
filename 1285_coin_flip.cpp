#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N;
char grid[20][20];

int f(int flipped_cols) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        int t_cnt = 0;
        for (int j = 0; j < N; j++) {
            t_cnt += (bool)(flipped_cols & (1 << j)) ^ (grid[i][j] == 'T');
        }
        res += min(t_cnt, N - t_cnt);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = N * N;
    for (int m = 0; m < (1 << N); m++) {
        ans = min(ans, f(m));
    }

    cout << ans << '\n';
}