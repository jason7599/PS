#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_points;
    cin >> n_points;

    vector<int> points(n_points);
    set<int> points_sorted;
    for (int& p : points) {
        cin >> p;
        points_sorted.insert(p);
    }
    
    unordered_map<int, int> comp_vals;
    int val = 0;
    for (int p : points_sorted) {
        comp_vals[p] = val++;
    }

    for (int p : points) {
        cout << comp_vals[p] << ' ';
    }
    cout << '\n';
}