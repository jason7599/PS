#include <iostream>

#define INF 987654321

using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num_tc; cin >> num_tc;

    while (num_tc--)
    {
        int num_nodes, num_paths, num_dests;
        int start_node;
        int target_path_node0, target_path_node1;

        cin >> num_nodes >> num_paths >> num_dests;
        cin >> start_node;
        cin >> target_path_node0 >> target_path_node1;

        for (int i = 0; i < num_paths; i++)
        {
            int from, to, dist; 
            cin >> from >> to >> dist;
            //   
        }

        for (int i = 0; i < num_dests; i++)
        {
            int dest; cin >> dest;
            //
        }
    }
}