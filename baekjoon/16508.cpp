#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0, _n = n; i < _n; i++)
#define RANGE(i, s, e) for (int i = s, _e = e; i <= _e; i++)
#define REP(n) for (int _ = 0, _n = n; _ < _n; _++)
#define STR(x) #x
#define DBG(x) cerr << #x << " = " << x << '\n'
#define EE(p) (ll)(1e##p)
#define LF cout << '\n'
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
template<typename T = int> T input() { T t; cin >> t; return t; }
template<typename T> T& input(T& t) { cin >> t; return t; }
template<typename... Args> void input(Args&... args) { ((cin >> args), ...); }
template<typename... Args> tuple<Args...> inputs() { tuple<Args...> t; apply([](auto&... args){input(args...);}, t); return t; }
template<typename T, int C> array<T, C> inputs() { array<T, C> arr; for (T& t : arr) cin >> t; return arr; }
template<typename... Args> void print(const Args&... args) { ((cout << args << ' '), ...); LF; }
template<typename T> T& upmax(T& v, const T& other) { return v = max(v, other); }
template<typename T> T& upmin(T& v, const T& other) { return v = min(v, other); }
const pii DIRS[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // drul

using freq_t = unordered_map<char, int>;

struct Book {
    int price;
    freq_t freq;
};

void get_freq(freq_t& freq, string& str) {
    for (char c : str) {
        freq[c]++;
    }
}

int n_books;
Book books[16];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    freq_t target_freq;
    string target_str = input<string>();
    get_freq(target_freq, target_str);

    FOR(i, input(n_books)) {
        input(books[i].price);
        string str = input<string>();
        get_freq(books[i].freq, str);
    }

    int min_price = INT_MAX;
    for (int m = 1; m < (1 << n_books); m++) {
        freq_t freq_sum;
        int price = 0;
        FOR(i, n_books) {
            if (m & (1 << i)) {
                price += books[i].price;
                for (auto& [c, cnt] : books[i].freq) {
                    freq_sum[c] += cnt;
                }
            }
        }

        bool good = 1;
        for (auto& [c, req] : target_freq) {
            if (target_freq[c] > freq_sum[c]) {
                good = 0;
                break;
            }
        }

        if (good) {
            upmin(min_price, price);
        }
    }

    print(min_price == INT_MAX ? -1 : min_price);
}