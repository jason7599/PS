#include <iostream>
#include <queue>
#include <algorithm>

/**
 * treat the destination (the exit) as a regular node,
 * and the exit warps become a regular edge to the exit
 * then we simply form the MST
 */

struct Warp
{
    int from;
    int to;
    int cost;
};

struct WarpCompare
{
    bool operator()(const Warp& lhs, const Warp& rhs) const
    {
        return lhs.cost > rhs.cost;
    }
};

int find_root(std::vector<int>& roots, int room)
{
    if (roots[room] != room)
        roots[room] = find_root(roots, roots[room]);
    return roots[room];
}

void make_union(std::vector<int>& roots, int root0, int root1)
{
    if (root0 < root1)
        roots[root0] = root1;
    else
        roots[root1] = root0;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_rooms, n_warps;
    std::cin >> n_rooms >> n_warps;

    std::priority_queue<Warp, std::vector<Warp>, WarpCompare> warps;

    for (int i = 0; i < n_warps; i++)
    {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        warps.push(Warp{from, to, cost});
    }

    std::vector<int> roots(n_rooms + 1);

    for (int room = 1; room <= n_rooms; room++)
    {
        roots[room] = room;

        int cost;
        std::cin >> cost;
        warps.push(Warp{room, 0, cost});
    }

    int total_cost = 0;
    while (!warps.empty())
    {
        const auto [from, to, cost] = warps.top();
        warps.pop();

        int root0 = find_root(roots, from);
        int root1 = find_root(roots, to);

        if (root0 == root1) // only for safe edges
            continue;
        
        total_cost += cost;

        make_union(roots, root0, root1);
    }

    std::cout << total_cost;
}