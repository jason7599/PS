#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define REP(n) for(int i = n; i > 0; i--)
#define RANGE(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T> T input() { T t; cin >> t; return t; } int input() { return input<int>(); }
template<typename T> void input(T& t) { cin >> t; }
template<typename T, typename... Args> void input(T& t, Args&... args) { cin >> t; input(args...); }
template<typename T> void print(const T& t) { cout << t << '\n'; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { cout << t << ' '; print(args...); }

vector<int> count_array(const string& str) {
    vector<int> arr(26);
    for (char c : str) {
        arr[c - 'A']++;
    }
    return arr;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_words = input();
    string base_str = input<string>();
    vector<int> base_cnt = count_array(base_str);

    int ans = 0;
    REP(n_words - 1) {
        string str = input<string>();
        if (abs((int)str.length() - (int)base_str.length()) > 1) {
        cont:
            continue;
        }
        vector<int> cnt = count_array(str);
        bool neg_diff = 0, pos_diff = 0;
        FOR(i, 26) {
            int diff = base_cnt[i] - cnt[i];
            if (diff) {
                if (abs(diff) != 1) {
                    goto cont;
                }
                if (diff == 1) {
                    if (pos_diff) {
                        goto cont;
                    }
                    pos_diff = 1;
                } else {
                    if (neg_diff) {
                        goto cont;
                    }
                    neg_diff = 1;
                }
            }
        }
        ans++;
    }

    print(ans);
}