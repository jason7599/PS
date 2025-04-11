#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_elems;
    cin >> n_elems;

    vector<int> elems(n_elems);
    for (int& e : elems) {
        cin >> e;
    }

    unordered_set<int> combs;
    for (int i = 0; i < n_elems; i++) {
        for (int j = i; j < n_elems; j++) {
            combs.insert(elems[i] + elems[j]);
        }
    }

    sort(elems.begin(), elems.end(), greater());
    for (int i = 0; i < n_elems; i++) {
        for (int j = i; j < n_elems; j++) {
            if (combs.count(elems[i] - elems[j])) {
                cout << elems[i] << '\n';
                return 0;
            }
        }
    }
}