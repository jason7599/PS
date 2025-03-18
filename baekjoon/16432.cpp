#include <bits/stdc++.h>

using namespace std;

bool visited[1001][10];

bool solve(const vector<vector<int>>& graph, int row_idx, int prev, vector<int>& ans) {
    if (row_idx == graph.size()) {
        return 1;
    }

    visited[row_idx][prev] = 1;

    for (int elem : graph[row_idx]) {
        if (elem != prev) {
            ans[row_idx] = elem;
            if (!visited[row_idx + 1][elem] && solve(graph, row_idx + 1, elem, ans)) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_rows;
    cin >> n_rows;

    vector<vector<int>> graph(n_rows);

    for (auto& row : graph) {
        int n_elems;
        cin >> n_elems;
        row.resize(n_elems);
        for (int& elem : row) {
            cin >> elem;
        }
    }

    vector<int> ans(n_rows);

    if (solve(graph, 0, 0, ans)) {
        for (int i : ans) {
            cout << i << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}