#include <iostream>
#include <algorithm>
#include <queue>

const int INF = 1e9;

struct Relation
{
    int with;
    int dist;
};

std::vector<int> get_shortest_path(const std::vector<std::vector<Relation>>& relations)
{
    int n_people = relations.size();

    std::vector<int> dist_map(n_people, INF);
    std::vector<int> prev_node(n_people);

    auto compare = [](const Relation& lhs, const Relation& rhs)
    {
        return lhs.dist > rhs.dist; 
    };

    std::priority_queue<Relation, std::vector<Relation>, decltype(compare)> pq(compare);
    
    pq.push(Relation{0, 0});
    dist_map[0] = 0;
    prev_node[0] = -1;

    while (!pq.empty())
    {
        const auto [cur_node, cur_dist] = pq.top();
        pq.pop();

        if (cur_node == n_people - 1)
            break;
        
        if (dist_map[cur_node] < cur_dist)
            continue;
        
        for (const auto [next, dist] : relations[cur_node])
        {
            int nx_dist = cur_dist + dist;
            if (nx_dist < dist_map[next])
            {
                dist_map[next] = nx_dist;
                prev_node[next] = cur_node;
                pq.push(Relation{next, nx_dist});
            }
        }
    }

    if (dist_map[n_people - 1] == INF)
        return {};

    std::vector<int> path;

    for (int node = n_people - 1; node != -1; node = prev_node[node])
        path.push_back(node);

    return path;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_tc;
    std::cin >> n_tc;
    for (int tc = 1; tc <= n_tc; tc++)
    {
        int n_people, n_relations;
        std::cin >> n_relations >> n_people;

        std::vector<std::vector<Relation>> relations(n_people, std::vector<Relation>(n_people));

        while (n_relations--)
        {
            int from, to, dist;
            std::cin >> from >> to >> dist;

            relations[from].push_back(Relation{to, dist});
            relations[to].push_back(Relation{from, dist});
        }

        std::vector<int> path = get_shortest_path(relations);

        std::cout << "Case #" << tc << ": ";
        if (path.empty())
            std::cout << -1;
        else
        {
            size_t i = path.size();
            while (i-- > 0)
                std::cout << path[i] << ' ';
        }
        std::cout << '\n';
    }
}