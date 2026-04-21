#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_cats, max_weight;
    cin >> n_cats >> max_weight;

    vector<int> weights(n_cats);
    for (int& w : weights) {
        cin >> w;
    }
    sort(weights.begin(), weights.end());

    int n_happy = 0;
    for (int l = 0, r = n_cats - 1; l < r;) {
        while (l < r && weights[l] + weights[r] > max_weight) {
            r--;
        }
        if (l < r) {
            n_happy++;
            l++, r--;
        }
    }
    cout << n_happy << '\n';
}