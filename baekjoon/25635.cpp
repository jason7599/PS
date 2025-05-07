#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    priority_queue<int> pq;
    while (n--) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int64_t ans = 0;
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        ans += second * 2;
        if (first - second) {
            pq.push(first - second);
        }
    }

    ans += !pq.empty();

    cout << ans << '\n';
}