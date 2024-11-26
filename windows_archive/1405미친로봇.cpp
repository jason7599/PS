#include <iostream>

using namespace std;

// e, w, s, n
const int dys[] = {0, 0, 1, -1};
const int dxs[] = {1, -1, 0, 0};

int move_probs[4];

double solve(int moves, int y = 14, int x = 14)
{
    static bool visited[29][29];

    if (moves == 0)
        return 1;

    visited[y][x] = true;

    double prob = 0;
    
    for (int d = 0; d < 4; d++)
    {
        int ny = y + dys[d];
        int nx = x + dxs[d];

        if (!visited[ny][nx])
            prob += move_probs[d] / (double)100 * solve(moves - 1, ny, nx);
    }

    visited[y][x] = false;

    return prob;
}

int main()
{
    int moves;

    cin >> moves;

    for (int d = 0; d < 4; d++)
        cin >> move_probs[d];

    cout.precision(10);
    cout << solve(moves);

    return 0;
}