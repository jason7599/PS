#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int raw[100'000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    FOR(i, n) {
        cin >> raw[i];
    }

    sort(raw, raw + n);

    vector<int> arr;
    for (int i = 0, prev = -1, dup = 0; i < n; i++) {
        if (raw[i] != prev) {
            arr.push_back(raw[i]);
            prev = raw[i];
            dup = 0;
        } else if (!dup) {
            arr.push_back(raw[i]);
            dup = 1;
        }
    }

    int max_score = 0;
    FOR(i, arr.size() - 1) {
        FORR(j, i + 1, arr.size() - 1) {
            int score = 0;
            for (int t = arr[i] * arr[j]; t; t /= 10) {
                score += t % 10;
            }
            max_score = max(max_score, score);
        }
    }

    PRINT(max_score)
}