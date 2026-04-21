#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n_presents, diff_cap;
pii presents[100'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n_presents >> diff_cap;
    for (int i = 0; i < n_presents; i++) {
        cin >> presents[i].first >> presents[i].second;
    }

    sort(presents, presents + n_presents);

    ll max_score = 0, score = 0;
    for (int l = 0, r = 0; l < n_presents; l++) {
        for (; r < n_presents 
            && presents[r].first - presents[l].first < diff_cap; r++) {
            score += presents[r].second;
        }
        max_score = max(max_score, score);
        score -= presents[l].second;
    }

    cout << max_score << '\n';
}