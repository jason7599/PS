#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;

    ll ans = 0;
    stack<pii> stk; // <height, cnt>

    while (n--) {
        int h;
        cin >> h;

        int t = 0;
        while (!stk.empty() && stk.top().first <= h) {
            ans += stk.top().second;
            if (stk.top().first == h) {
                t = stk.top().second;
            }
            stk.pop();
        }

        if (!stk.empty()) {
            ans++;
        }

        stk.push({h, t + 1});
    }

    PRINT(ans)
}