#include <bits/stdc++.h>
using namespace std;

pair<int, int> parse(const string& s) {
    size_t t = s.find('C', 1);
    return {stoi(s.substr(1, t - 1)), stoi(s.substr(t + 1))};
}

string col_name(int n) {
    stack<char> stk;
    for (n--; n; n /= 26) {
        stk.push('A' - 1 + (n % 26));
    }
    if (stk.empty()) {
        stk.push('A' - 1);
    }
    string res;
    for (; !stk.empty(); stk.pop()) {
        res.push_back(stk.top());
    }
    res.back()++;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (string s; getline(cin, s);) {
        auto [row, col] = parse(s);
        if (!row && !col) {
            break;
        }
        cout << col_name(col) << row << '\n';
    }
}