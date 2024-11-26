#include <iostream>
#include <vector>

using namespace std;

vector<int> hoses[51];
float water[51];

int main()
{
    int num_buckets, num_hoses;
    cin >> num_buckets >> num_hoses;

    for (int i = 0; i < num_hoses; i++)
    {
        int v, w;
        cin >> v >> w;
        hoses[v].push_back(w);
    }

    water[1] = 100;

    float most_water = 0;

    for (int bucket = 1; bucket <= num_buckets; bucket++)
    {
        const vector<int>& connections = hoses[bucket];

        if (connections.empty())
        {
            if (water[bucket] > most_water)
                most_water = water[bucket];
        }
        else
        {
            float flow_amount = water[bucket] / connections.size();
            for (int connection : connections)
                water[connection] += flow_amount;
        }
    }

    cout << most_water;
    return 0;
}