#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

struct PNode
{
    double royalty = 0;
    std::string parent0;
    std::string parent1;
    std::vector<std::string> children;
};

std::string king_name;

std::unordered_map<std::string, PNode> family;

void dfs(const std::string& name, std::unordered_set<std::string>& visited, std::stack<std::string>& res)
{
    visited.insert(name);
    
    for (const std::string& child_name : family.at(name).children)
    {
        if (visited.count(child_name) == 0)
            dfs(child_name, visited, res);
    }

    res.push(name);
}

std::stack<std::string> topologic_sort()
{
    std::stack<std::string> res;
    std::unordered_set<std::string> visited;

    dfs(king_name, visited, res);

    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_family_info, n_candidates;
    std::cin >> n_family_info >> n_candidates;

    std::cin >> king_name;

    family[king_name].royalty = 1;

    for (int i = 0; i < n_family_info; i++)
    {
        std::string name, pname0, pname1;
        std::cin >> name >> pname0 >> pname1;

        PNode &pnode = family[name];
        pnode.parent0 = pname0;
        pnode.parent1 = pname1;

        PNode &parent0 = family[pname0];
        PNode &parent1 = family[pname1];

        parent0.children.push_back(name);
        parent1.children.push_back(name);
    }

    std::unordered_set<std::string> candidates;

    while (n_candidates--)
    {
        std::string candidate;
        std::cin >> candidate;
        candidates.insert(candidate);
    }

    std::stack<std::string> topo_stack = topologic_sort();
    
    double max_royalty = 0;
    std::string best_candidate;

    topo_stack.pop(); // king

    while (!topo_stack.empty() && !candidates.empty())
    {
        std::string name = topo_stack.top();
        topo_stack.pop();

        PNode& pnode = family[name];

        double royalty = pnode.royalty = (family[pnode.parent0].royalty + family[pnode.parent1].royalty) / 2;
        
        if (candidates.count(name))
        {
            if (royalty > max_royalty)
            {
                max_royalty = royalty;
                best_candidate = name;
            }
            candidates.erase(name);
        } 
    }

    std::cout << best_candidate << '\n';
}