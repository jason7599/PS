#include <bits/stdc++.h>

using namespace std;

int dp[100][501];

int solve(const vector<pair<int, int>>& wires, int idx, int top) {
    if (idx == wires.size()) {
        return 0;
    }
    
    int& res = dp[idx][top];
    if (res) {
        return max(res, 0);
    }

    res = 1 + solve(wires, idx + 1, top);
    if (wires[idx].second > top) {
        res = min(res, solve(wires, idx + 1, wires[idx].second));
    }

    if (!res) {
        res = -1;
        return 0;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_wires;
    cin >> n_wires;

    vector<pair<int, int>> wires(n_wires);
    for (auto& [s, e] : wires) {
        cin >> s >> e;
    }

    sort(wires.begin(), wires.end());

    cout << solve(wires, 0, 0) << '\n';
}