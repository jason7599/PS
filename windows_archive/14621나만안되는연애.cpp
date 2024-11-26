#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int root[1'000];

int findSet(int school)
{
    if (root[school] != school)
        root[school] = findSet(root[school]);
    return root[school];
}

void makeSet(int school0, int school1)
{
    int root0 = findSet(school0);
    int root1 = findSet(school1);

    if (root0 < root1)
        root[root1] = root0;
    else
        root[root0] = root1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numSchools, numRoads;
    cin >> numSchools >> numRoads;

    bool isMaleSchool[1'000];
    for (int i = 0; i < numSchools; i++)
    {
        char c; cin >> c;
        isMaleSchool[i] = c == 'M';
        root[i] = i;
    }

    vector<pair<int, pair<int, int>>> roads;
    for (int i = 0; i < numRoads; i++)
    {
        int school0, school1, dist;
        cin >> school0 >> school1 >> dist;
        school0--, school1--;

        if (isMaleSchool[school0] ^ isMaleSchool[school1])
            roads.push_back({dist, {school0, school1}});
    }

    sort(roads.begin(), roads.end());

    int mstDist = 0;
    int conRoads = 0;
    for (int i = 0; i < roads.size(); i++)
    {
        int dist = roads[i].first;
        int school0 = roads[i].second.first;
        int school1 = roads[i].second.second;

        if (findSet(school0) != findSet(school1))
        {
            makeSet(school0, school1);
            mstDist += dist;
            conRoads++;
        }
    }

    if (conRoads == numSchools - 1)
        cout << mstDist;
    else
        cout << -1;

    return 0;
}