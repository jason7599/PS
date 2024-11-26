#include <iostream>
#include <set>
#include <queue>

using namespace std;

/*
 * 우산 먹으면 새로이 bfs
*/

typedef pair<int,int> pii;

const int max_map_size = 500;

int map_size;
set<pii> umbrellas;
int umbrella_durability;
pii dest_pos;

int main()
{

    int a = 10;
    

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int start_health;
    pii start_pos;

    cin >> map_size >> start_health >> umbrella_durability;

    for (int y = 0; y < map_size; y++)
    {
        for (int x = 0; x < map_size; x++)
        {
            char c; cin >> c;
            switch (c)
            {
                case 'S': start_pos = {y, x}; break;
                case 'U': umbrellas.insert({y, x}); break;
                case 'E': dest_pos = {y, x}; break;
                default:
            }
        }
    }

    
}