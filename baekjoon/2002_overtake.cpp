#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_cars;
    cin >> n_cars;

    unordered_map<string, int> old_idxs;
    for (int i = 0; i < n_cars; i++) {
        string car;
        cin >> car;
        old_idxs[car] = i;
    }

    vector<int> new_idxs(n_cars);
    for (int& idx : new_idxs) {
        string car;
        cin >> car;
        idx = old_idxs[car];
    }

    int next_idx = 0;
    int n_overtakes = 0;
    vector<bool> checked(n_cars);
    
    int i = 0;
    while (next_idx < n_cars) {
        while (new_idxs[i] != next_idx) {
            checked[new_idxs[i++]] = 1;
            n_overtakes++;
        }
        checked[next_idx++] = 1;
        while (checked[next_idx]) {
            next_idx++;
        }
        i++;
    }

    cout << n_overtakes << '\n';
}