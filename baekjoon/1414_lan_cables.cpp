#include <bits/stdc++.h>

inline int parse_len(char c)
{
    if (c == '0')
        return 0;
    if (c >= 'a')
        return c - 'a' + 1;
    return c - 'A' + 27;
}

struct Conn
{
    int length;
    int from, to;
};

struct ConnCmp
{
    bool operator()(const Conn& lhs, const Conn& rhs) const
    {
        return lhs.length > rhs.length;
    }
};

int find_root(std::vector<int>& roots, int node)
{
    if (roots[node] != node)
        roots[node] = find_root(roots, roots[node]);
    return roots[node];
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_nodes;
    std::cin >> n_nodes;

    std::vector<int> roots(n_nodes);
    std::priority_queue<Conn, std::vector<Conn>, ConnCmp> conns;

    int total_len = 0;

    for (int i = 0; i < n_nodes; i++)
    {
        roots[i] = i;
        for (int j = 0; j < n_nodes; j++)
        {
            char c;
            std::cin >> c;
            
            int len = parse_len(c);
            if (len)
                conns.push(Conn{len, i, j});

            total_len += len;
        }
    }

    int n_conns = 0;
    int conn_len = 0;
    while (!conns.empty())
    {
        const auto [len, from, to] = conns.top();
        conns.pop();

        int root0 = find_root(roots, from);
        int root1 = find_root(roots, to);

        if (root0 != root1)
        {
            if (root0 > root1)
                roots[root1] = root0;
            else
                roots[root0] = root1;

            n_conns++;
            conn_len += len;
        }
    }

    if (n_conns != n_nodes - 1)
        std::cout << -1;
    else
        std::cout << total_len - conn_len;
}