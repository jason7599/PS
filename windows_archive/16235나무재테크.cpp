#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int landSize;
    int nourishment[10][10];
    int nourishmentRefill[10][10];
    list<int> trees[10][10];
    int initTreeCount;
    int years;

    cin >> landSize >> initTreeCount >> years;

    for (int y = 0; y < landSize; y++)
    {
        for (int x = 0; x < landSize; x++)
        {
            cin >> nourishmentRefill[y][x];
            nourishment[y][x] = 5;
        }
    }

    while (initTreeCount--)
    {
        int y, x, age;
        cin >> y >> x >> age;
        trees[y - 1][x - 1].push_back(age);
    }

    int treeCount;
    while (years--)
    {
        treeCount = 0;
        vector<pair<int,int>> treesForFall;
        for (int y = 0; y < landSize; y++)
        {
            for (int x = 0; x < landSize; x++)
            {
                int dead = 0;
                list<int> copy;
                for (int age : trees[y][x])
                {
                    if (nourishment[y][x] >= age)
                    {
                        nourishment[y][x] -= age;
                        if (++age % 5 == 0)
                        {
                            for (int ny = y - 1; ny <= y + 1; ny++)
                            {
                                for (int nx = x - 1; nx <= x + 1; nx++)
                                {
                                    if (ny == y && nx == x)
                                        continue;
                                    if (ny < 0 || ny == landSize || nx < 0 || nx == landSize)
                                        continue;
                                    treesForFall.push_back({ny, nx});
                                    treeCount++;
                                }
                            }
                        }
                        copy.push_back(age);
                        treeCount++;
                    }
                    else
                    {
                        dead += age / 2;
                    }
                }
                trees[y][x] = copy;
                nourishment[y][x] += dead + nourishmentRefill[y][x];
            }
        }

        if (!treeCount) break;

        for (pair<int,int> t : treesForFall)
            trees[t.first][t.second].push_front(1);
    }

    cout << treeCount;
}