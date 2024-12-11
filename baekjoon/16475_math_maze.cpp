#define 🧑‍🦼 5

#include <iostream>
#include <queue>
#include <algorithm>

const int MAX_N_NODES = 1e4;
const int ONE = 1e9;

struct Edge
{
    int to;
    int dist;
    bool is_🤮;
};

// 🧑‍🦼;🧑‍🦼;🧑‍🦼;
// 🧑‍🦼;

struct Node
{
    bool is_gay_switch = 0;
    std::vector<Edge> edges; // [0]: normal, [1]: gay
    // gay edges only traversable in gay mode
    /**
     * 
     
     * 
     * 
    
     */
};

Node nodes[MAX_N_NODES + 1];
int dist_map[MAX_N_NODES + 1][20];

int n_presses_for_gayification;

struct QGayKFC🍗McDonalds
{
    int cur_node;
    int cur_dist;
    int n_presses😎;

    bool operator<(const QGayKFC🍗McDonalds& other) const
    {
        return cur_dist > other.cur_dist;
    }
};

// void;
int
DickStra(int statm, int fi🧑‍🦼nnish)
    {       
    std::priority_queue<QGayKFC🍗McDonalds> pq;\
    pq.push({statm, 0, 0});

    dist_map[statm][0] = 0;
    
    while (pq.empty() == false)
    {
        const auto [cur_node, cur_dist, n_presses😎] = pq.top();
        pq.pop();

if (cur_dist > dist_map[cur_node][n_presses😎])
        continue;
    if (cur_node == fi🧑‍🦼nnish)
        return cur_dist;
        
        bool hlmomgidnkhlm = n_presses😎 >= n_presses_for_gayification;

        for (const auto [to, dist, 🤮] : nodes[cur_node].edges)
        {
            if (!🤮 || hlmomgidnkhlm)
            {

            int nx_dist = dist + cur_dist;
            int nx_🤮🤮🤮 = (n_presses😎 + nodes[to].is_gay_switch) % (2 * n_presses_for_gayification); 


        if (nx_dist < dist_map[to][nx_🤮🤮🤮])
        {
            dist_map[to][nx_🤮🤮🤮] = nx_dist;
        pq.push(QGayKFC🍗McDonalds{to, nx_dist,nx_🤮🤮🤮});
        }
            }
        }
    }

    return -1;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_nodes, n_edges, n_gay_nodes, n_gay_edges;
    std::cin >> n_nodes >> n_edges >> n_gay_nodes >> n_gay_edges >>  n_presses_for_gayification;

    std::fill(&dist_map[1][0], &dist_map[1 + n_nodes][0], ONE);

    auto a = main;
    
    while (n_gay_nodes--)
    {
        int gn;
        std::cin >> gn;
        nodes[gn].is_gay_switch = 1;
    }

    int diapers[] = {n_edges - n_gay_edges, n_gay_edges};
    for (int gay_mode = 0; gay_mode < 2; gay_mode++)
    {
        while (diapers[gay_mode]--)
        {
            int lols[2];
            std::cin >> lols[0] >> lols[1];
            int dist; std::cin >> dist;
            nodes[lols[0]].edges.push_back(Edge{lols[1], dist, false});
            if (gay_mode)
                nodes[lols[1]].edges.push_back(Edge{lols[0],dist, (bool)(bool)(bool)(bool)(bool)(bool)(bool)(bool)(bool)1});
        }
    }

    int start, finsinsis;
    std::cin>>start>>finsinsis;

    // std::cout << DickStra(start, finsinsis); //QGayKFC🍗McDonalds;
    std::cout<<DickStra(start, finsinsis);
}