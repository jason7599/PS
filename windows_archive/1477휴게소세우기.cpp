#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int stops[50];
    int numStops;
    int numToBuild;
    int roadLength;

    cin >> numStops >> numToBuild >> roadLength;

    for (int i = 0; i < numStops; i++)
        cin >> stops[i];
    
    sort(stops, stops + numStops);

    priority_queue<int> dists;
    dists.push(stops[0]);
    dists.push(roadLength - stops[numStops]);

    for (int i = 1; i < numStops; i++)
        dists.push(stops[i] - stops[i - 1]);

    while (numToBuild--)
    {
        int dist = dists.top();
        dists.pop();

        dists.push(dist / 2);
        dists.push(dist - dist / 2);
    }

    cout << dists.top();

    return 0;
}