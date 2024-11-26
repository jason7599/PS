#include <iostream>
#include <vector>

using namespace std;

struct Island
{
    long long quantity;
    bool isWolf;
    vector<int> paths;
};

Island islands[123'457];

long long answer;

void solve(const Island& island, long long wolvesInPath)
{
    if (island.isWolf)
    {
        wolvesInPath += island.quantity;
    }
    else
    {
        if (island.quantity > wolvesInPath) // 양이 더 많다
        {
            answer += island.quantity - wolvesInPath;
            wolvesInPath = 0;
        }
        else // 늑대가 더 많다
        {
            wolvesInPath -= island.quantity; 
        }
    }

    for (int path : island.paths)
    {
        solve(islands[path], wolvesInPath);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numIslands; cin >> numIslands;

    for (int i = 2; i <= numIslands; i++)
    {
        char type; long long quantity; int parent;
        cin >> type >> quantity >> parent;

        islands[i].quantity = quantity;
        islands[i].isWolf = type == 'W';

        islands[parent].paths.push_back(i);
    }

    solve(*(islands + 1), 0);

    cout << answer;

    return 0;
}