#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_tc;
    cin >> n_tc;

    while (n_tc--) {
        int a_cnt, b_cnt;
        cin >> a_cnt >> b_cnt;
        vector<int> A(a_cnt);
        vector<int> B(b_cnt);
        for (int& a : A) {
            cin >> a;
        }
        for (int& b : B) {
            cin >> b;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int ans = 0;
        int b_ptr = 0;
        for (int a_ptr = 0; a_ptr < a_cnt; a_ptr++) {
            while (b_ptr < b_cnt && A[a_ptr] > B[b_ptr]) {
                b_ptr++;
            }
            ans += b_ptr;
            if (b_ptr == b_cnt) {
                ans += (a_cnt - a_ptr - 1) * b_cnt;
                break;
            }
        }
        cout << ans << '\n';
    }
}