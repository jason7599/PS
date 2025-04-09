#include <bits/stdc++.h>

using namespace std;

int dp[4][10'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_queries;
    cin >> n_queries;
    vector<int> queries(n_queries);
    int max_val = 0;
    for (int& q : queries) {
        cin >> q;
        max_val = max(max_val, q);
    }


}