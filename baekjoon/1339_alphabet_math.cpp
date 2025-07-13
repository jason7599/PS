#include <bits/stdc++.h>
#define COUT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int n_words;
string words[10];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n_words;
    unordered_map<char, int> cnt;
    FOR(i, n_words) {
        string& w = words[i];
        cin >> w;
        for (int j = w.length() - 1, t = 1; j >= 0; j--, t *= 10) {
            cnt[w[j]] += t;
        }
    }

    priority_queue<pair<int, char>> pq;
    for (const auto& [c, f] : cnt) {
        pq.push({f, c});
    }

    ll ans = 0;
    for (int v = 9; pq.size(); v--, pq.pop()) {
        ans += (ll)pq.top().first * v;
    }

    COUT(ans)
}