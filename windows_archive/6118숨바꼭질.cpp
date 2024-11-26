#include <iostream>
#include <queue>

using namespace std;

vector<int> roads[50'001];
bool v[50'001];

void solve()
{
    queue<int> q({1});
    v[1] = 1;

    int max_dist_barn;
    int num_max_dist;
    int max_dist = -1;
    
    int dist = 0;
    int t;
    while ((t = q.size()))
    {
        while (t--)
        {
            int barn = q.front();
            q.pop();

            if (dist > max_dist)
            {
                max_dist = dist;
                max_dist_barn = barn;
                num_max_dist = 1;
            }
            else if (dist == max_dist)
            {
                num_max_dist++;
                if (barn < max_dist_barn)
                    max_dist_barn = barn;
            }

            for (int other_barn : roads[barn])
            {
                if (!v[other_barn])
                {
                    v[other_barn] = true;
                    q.push(other_barn);
                }
            }
        }
        dist++;
    }

    cout << max_dist_barn << ' ' << max_dist << ' ' << num_max_dist;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_barns, num_roads;
    cin >> num_barns >> num_roads;

    for (int i = 0; i < num_roads; i++)
    {
        int barn0, barn1;
        cin >> barn0 >> barn1;
        roads[barn0].push_back(barn1);
        roads[barn1].push_back(barn0);
    }

    solve();

    return 0;
}