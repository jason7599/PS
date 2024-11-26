#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> points[100'000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_points; cin >> num_points;

    for (int i = 0; i < num_points; i++)
    {
        int x, y; cin >> x >> y;
        points[i] = {x, y};
    }

    sort(points, points + num_points);

    for (int i = 0; i < num_points; i++)
    {
        cout << points[i].first << ' ' << points[i].second << '\n';
    }

    return 0;
}