#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set> // ordering matters for result

using Graph = std::unordered_map<std::string, std::vector<std::string>>;

struct Command
{
    std::string lhs;
    std::string rhs;
};

Command parse_command(const std::string& line)
{
    size_t t = line.find(' ');
    return Command {
        line.substr(0, t),
        line.substr(t + 4)
    };
}

void dfs(const Graph& graph, const std::string& cur, std::set<std::string>& visited)
{
    if (!graph.count(cur))
        return;
    
    for (const std::string& adj : graph.at(cur))
    {
        if (!visited.count(adj))
        {
            visited.insert(adj);
            dfs(graph, adj, visited);
        }
    }
}

std::set<std::string> get_babas_dest(const Graph& graph)
{
    std::set<std::string> visited;
    dfs(graph, "Baba", visited);
    return visited;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n_commands;
    std::cin >> n_commands;

    std::cin.ignore();

    Graph graph;

    while (n_commands--)
    {
        std::string line;
        std::getline(std::cin, line);

        Command cmd = parse_command(line);

        graph[cmd.lhs].push_back(cmd.rhs);
    }

    auto dests = get_babas_dest(graph);

    for (const std::string& dest : dests)
        std::cout << dest << '\n';
}