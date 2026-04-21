#include <bits/stdc++.h>
#define PRINT(x) {cout << x << '\n';}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n_tc;
    cin >> n_tc;
    FORR(tc, 1, n_tc) {
        int n_ppl, n_cars, n_areas;
        cin >> n_ppl >> n_cars >> n_areas;

        vector<pii> ppl_per_area(n_areas + 1);
        vector<priority_queue<int>> cars_per_area(n_areas + 1); // <cap>
        FOR(i, n_ppl) {
            int area;
            char c;
            cin >> area >> c;
            if (c == 'S') {
                ppl_per_area[area].first++;
            } else {
                ppl_per_area[area].second++;
            }
        }

        FOR(i, n_cars) {
            int area, cap;
            cin >> area >> cap;
            cars_per_area[area].push(cap);
        }

        int ans = n_ppl;
        FORR(a, 1, n_areas) {
            while (ppl_per_area[a].first && !cars_per_area[a].empty()) {
                int n_total = ppl_per_area[a].first + ppl_per_area[a].second;
                if (n_total <= cars_per_area[a].top()) {
                    ans -= n_total;
                    break;
                }
                int n_drunks = min(ppl_per_area[a].second - 1, cars_per_area[a].top() - 1);
                ppl_per_area[a].first--;
                ppl_per_area[a].second -= n_drunks;
                ans -= n_drunks + 1;
                cars_per_area[a].pop();
            }
        }

        cout << "Data Set " << tc << ":\n";
        PRINT(ans)
    }
}