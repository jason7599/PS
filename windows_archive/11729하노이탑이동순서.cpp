#include <iostream>

using namespace std;

void solve(int from, int to, int plates)
{
    if (plates == 1)
    {
        cout << from << ' ' << to << '\n';
        return;
    }

    int other = 6 - from - to;

    solve(from, other, plates - 1);
    cout << from << ' ' << to << '\n';
    solve(other, to, plates - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_plates; cin >> num_plates;
    cout << (1 << num_plates) - 1 << '\n';
    solve(1, 3, num_plates);
}