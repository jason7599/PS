#include <bits/stdc++.h>
using namespace std;

bool solve(const string& src0, const string& src1, const string& dst, size_t idx0 = 0, size_t idx1 = 0) {
    static vector<vector<char>> dp;

    size_t idx = idx0 + idx1;
    if (idx == dst.length()) {
        return 1;
    }

    if (!idx) {
        dp.clear();
        dp.resize(src0.length() + 1, vector<char>(src1.length() + 1, -1));
    }

    char& res = dp[idx0][idx1];
    if (res != -1) {
        return res;
    }

    if (dst[idx] == src0[idx0]) {
        if (dst[idx] == src1[idx1]) {
            return res = solve(src0, src1, dst, idx0 + 1, idx1)
                || solve(src0, src1, dst, idx0, idx1 + 1);
        }
        return res = solve(src0, src1, dst, idx0 + 1, idx1);
    }
    if (dst[idx] == src1[idx1]) {
        return res = solve(src0, src1, dst, idx0, idx1 + 1);
    }
    return res = 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_tc;
    cin >> n_tc;
    for (int tc = 1; tc <= n_tc; tc++) {
        string src0, src1, dst;
        cin >> src0 >> src1 >> dst;

        cout << "Data set " << tc << ": ";
        if (solve(src0, src1, dst)) {
            cout << "yes";
        } else {
            cout << "no"; 
        }
        cout << '\n';
    }
}