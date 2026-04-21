#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    while (1) {
        int n;
        cin >> n;
        if (!n) {
            break;
        }
        vector<int> arr(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        stack<pii> stk; // <h, x>
        ll max_size = 0;
        for (int i = 0; i < n + 1; i++) {
            int h = arr[i];

            int lx = -1;
            while (!stk.empty() && stk.top().first > h) {
                ll size = (ll)stk.top().first * (i - stk.top().second);
                lx = stk.top().second;
                max_size = max(max_size, size);
                stk.pop();
            }

            if (lx != -1 && h) {
                stk.push({h, lx});
            }

            if (!stk.empty() && stk.top().first == h) {
                continue;
            }

            stk.push({h, i});
        }
        cout << max_size << '\n';
    }
}