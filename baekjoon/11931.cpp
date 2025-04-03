#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_elems;
    cin >> n_elems;

    vector<int> elems(n_elems);
    for (int& elem : elems) {
        cin >> elem;
    }

    sort(elems.begin(), elems.end(), greater<>());
    for (int elem : elems) {
        cout << elem << '\n';
    }
}