#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int numRow, numCol;
pii root[500][500];

pii findRoot(pii node)
{
    if (root[node.first][node.second] != node)
    {
        root[node.first][node.second] = findRoot(root[node.first][node.second]);
    }
    return root[node.first][node.second];
}

void makeUnion(pii node0, pii node1)
{
    pii root0 = findRoot(node0);
    pii root1 = findRoot(node1);

    int rank0 = node0.first * 500 + node0.second;
    int rank1 = node1.first * 500 + node1.second;

    if (rank0 < rank1)
    {
        root[root0.first][root0.second] = root1;
    }
    else
    {
        root[root1.first][root1.second] = root0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numTC;
    cin >> numTC;

    while (numTC--)
    {
        cin >> numRow >> numCol;

        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                root[i][j] = {i, j};
            }
        }

        vector<pair<int, pair<pii, pii>>> edges;

        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol - 1; j++)
            {
                int d;
                cin >> d;

                edges.push_back({d, {{i, j}, {i, j + 1}}});
            }
        }

        for (int i = 0; i < numRow - 1; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                int d;
                cin >> d;

                edges.push_back({d, {{i, j}, {i + 1, j}}});
            }
        }

        sort(edges.begin(), edges.end());

        int minDist = 0;

        for (int i = 0; i < edges.size(); i++)
        {
            int d = edges[i].first;
            pii node0 = edges[i].second.first;
            pii node1 = edges[i].second.second;

            if (findRoot(node0) != findRoot(node1))
            {
                makeUnion(node0, node1);
                minDist += d;
            }
        }

        cout << minDist << '\n';
    }

    return 0;
}