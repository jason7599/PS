#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

/**
 * M이 괜사리 큰거네. 차피 z 넘어서 못 가니까.
 * 예를 들어 str = ab 이런 식이면, i=0에선 최대 25번 조작, i=1에선 최대 24번 조작하는 거까지만 의미가 있다
 * 실질적으로 사용할 수 있는 조작의 수는 SUM('z' - str[i]) 이거 아녀?
 * ab면 25 + 24 = 49
 * 그럼 최대는 사실상 300 * 25니까 할만하겠다
 */

const int MOD = 1e9 + 7;

int len;
string str;
int dp[300][25 * 300 + 1];

int f(int i, int n_ops) {
    if (!n_ops) {
        return 1;
    }

    if (i == len) {
        return 0;
    }

    int& res = dp[i][n_ops];
    if (res) {
        return res;
    }

    for (int ops = 0; ops <= n_ops; ops++) {
        int t = f(i + 1, n_ops - ops);
        res = (res + t) % MOD;
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll m;
    cin >> len >> m >> str; 

    int n_ops = 0;
    for (char c : str) {
        n_ops += 'z' - c;
    }

    cout << f(0, (int)min(m, (ll)n_ops)) << '\n';
}