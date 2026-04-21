#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n;
vector<int> arr1, arr2;

int f(int i1, int i2, int nz1, int nz2) {
    if (i1 == arr1.size() || i2 == arr2.size()) {
        return 0;
    }

    int t = arr1[i1] * arr2[i2];
    int res = t + f(i1 + 1, i2 + 1, nz1, nz2);
    if (t > 0) {
        return res;
    }

    if (nz1) {
        res = max(res, f(i1, i2 + 1, nz1 - 1, nz2));
    }

    if (nz2) {
        res = max(res, f(i1 + 1, i2, nz1, nz2 - 1));
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;

    int nz1, nz2;
    for (int i = 0; i < 2; i++) {
        vector<int>& arr = i ? arr1 : arr2;
        int& nz = i ? nz1 : nz2;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x) {
                arr.push_back(x);
            } else {
                nz++;
            }
        }
    }

    cout << f(0, 0, nz1, nz2) << '\n';
}