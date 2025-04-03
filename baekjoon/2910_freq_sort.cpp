#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_elems, max_elem;
    cin >> n_elems >> max_elem;

    struct Elem {
        int val;
        int first_idx;
        int freq;
    };

    unordered_map<int, Elem> freq_map;
    for (int i = 0; i < n_elems; i++) {
        int val;
        cin >> val;
        if (freq_map.count(val) == 0) {
            freq_map[val] = {val, i, 1};
        } else {
            freq_map[val].freq++;
        }
    }

    vector<Elem> elems(freq_map.size());
    int i = 0;
    for (const auto& [val, elem] : freq_map) {
        elems[i++] = elem;
    }

    sort(elems.begin(), elems.end(), [](Elem& lhs, Elem& rhs) {
        if (lhs.freq == rhs.freq) {
            return lhs.first_idx < rhs.first_idx;
        }
        return lhs.freq > rhs.freq;
    });

    for (const Elem& elem : elems) {
        for (int i = 0; i < elem.freq; i++) {
            cout << elem.val << ' ';
        }
    }
    cout << '\n';
}