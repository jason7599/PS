#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n;
int arr[40];
int target;
unordered_map<int, string> m; // val, bitstring

bool f(int end, int idx, int val, string str, bool chk) {
    if (chk) {
        if (m.count(target - val)) {
            string t = m[target - val] + str;
            cout << string(n - t.length(), '0') + t << '\n';
            return 1;
        }
    }
    if (idx == end) {
        if (!chk) {
            m.emplace(val, str);
        }
        return 0;
    }

    if (f(end, idx + 1, val, str + '0', chk) && chk) {
        return 1;
    }

    if (val + arr[idx] <= target && f(end, idx + 1, val + arr[idx], str + '1', chk) && chk) {
        return 1;
    } 

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    f(n / 2, 0, 0, "", 0);
    f(n, n / 2, 0, "", 1);
}
