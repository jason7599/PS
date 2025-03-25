#include <bits/stdc++.h>

using namespace std;

const int STICK_REQS[10] = {
    6,
    2,
    5,
    5,
    4,
    5,
    6,
    3,
    7,
    6,
};

bool bignum_cmp(const string& lhs, const string& rhs) {
    if (lhs.length() == rhs.length()) {
        int i = 0;
        while (lhs[i] == rhs[i]) {
            i++;
        }
        if (i == lhs.length()) {
            return 0;
        }
        return lhs[i] < rhs[i];
    }
    return lhs.length() < rhs.length();
}

pair<string, string> solve(int n_sticks, bool init) {
    static pair<string, string> cache[101][2];

    if (!n_sticks) {
        return {"", ""};
    }

    if (n_sticks == 1) {
        return {"-1", "-1"};
    }

    auto& res = cache[n_sticks][init];
    if (!res.first.empty()) {
        return res;
    }

    string min_str, max_str;

    for (int num = init; num < 10; num++) {
        if (STICK_REQS[num] <= n_sticks) {
            auto [t_min, t_max] = solve(n_sticks - STICK_REQS[num], 0);
            if (t_min != "-1") {
                t_min = (char)(num + '0') + t_min;
                if (min_str.empty() || bignum_cmp(t_min, min_str)) {
                    min_str = t_min;
                }
            }
            if (t_max != "-1") {
                t_max = (char)(num + '0') + t_max;
                if (max_str.empty() || bignum_cmp(max_str, t_max)) {
                    max_str = t_max;
                }
            }
        }
    }

    return res = {min_str, max_str};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_tc;
    cin >> n_tc;

    while (n_tc--) {
        int n_sticks;
        cin >> n_sticks;
        const auto& [min_str, max_str] = solve(n_sticks, 1);
        cout << min_str << ' ' << max_str << '\n';
    }
}