#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_crane;
    cin >> n_crane;
    vector<int> cranes(n_crane);
    for (int& i : cranes) {
        cin >> i;
    }

    int n_box;
    cin >> n_box;
    vector<int> boxes(n_box);
    for (int& i : boxes) {
        cin >> i;
    }

    sort(cranes.begin(), cranes.end());
    sort(boxes.begin(), boxes.end());

    if (cranes.back() < boxes.back()) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> resps(n_crane);
    for (int c = 0, b = 0; c < n_crane && b < n_box; c++) {
        while (b < n_box && boxes[b] <= cranes[c]) {
            resps[c]++, b++;
        }
    }

    for (int i = 0; i < n_crane; i++) {
        cout << "resp of " << cranes[i] << ": " << resps[i] << '\n';
    }

    
}
