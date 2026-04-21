#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    priority_queue<int> pq;
    while (n--) {
        int x;
        cin >> x;
        pq.push(-x);
    }

    int ans = 0;
    while (pq.size() > 1) {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();

        ans += a + b;
        pq.push(-a - b);
    }

    PRINT(ans)
}