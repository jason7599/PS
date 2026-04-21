#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<pii> arr(n);
    for (auto& [e, s] : arr) {
        cin >> s >> e; // <end, start>
    }

    sort(arr.begin(), arr.end()); 

    int ans = 0;
    int last = 0;
    for (const auto& [e, s] : arr) {
        if (last > s) {
            continue;
        }
        ans++;
        last = e;
    }

    cout << ans << '\n';
}
