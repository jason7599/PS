#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n_points;
    cin >> n_points;
    vector<pair<int, int>> points(n_points);
    for (auto& [x, y] : points) {
        cin >> y >> x;
    }
    sort(points.begin(), points.end());
    for (const auto& [x, y] : points) {
        cout << y << ' ' << x << '\n';
    }
}