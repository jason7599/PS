#include <bits/stdc++.h>
#define COUT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int n;
string arr[1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    FOR(i, n) {
        cin >> arr[i];
    }

    sort(arr, arr + n, [](const string& lhs, const string& rhs) {
        return lhs + rhs > rhs + lhs;
    });

    if (arr[0] == "0") {
        COUT(0)
    } else {
        FOR(i, n) {
            cout << arr[i];
        }
        cout << '\n';
    }
}