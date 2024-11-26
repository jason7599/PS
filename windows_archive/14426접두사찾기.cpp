#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int children[26] = {0};
};

vector<Node> nodes {Node()};

void add_word(const string& word)
{
    int node_idx = 0;

    for (char c : word)
    {
        int n_idx = nodes[node_idx].children[c - 'a'];
        if (!n_idx)
        {
            n_idx = nodes[node_idx].children[c - 'a'] = nodes.size();
            nodes.push_back(Node());
        }
        node_idx = n_idx;
    }
}

bool find_prefix(const string& prefix)
{
    int node_idx = 0;
    
    for (char c : prefix)
    {
        int n_idx = nodes[node_idx].children[c - 'a'];
        if (!n_idx)
            return 0;
        node_idx = n_idx;
    }

    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int num_words, num_prefixes;
    cin >> num_words >> num_prefixes;

    for (int i = 0; i < num_words; i++)
    {
        string word;
        cin >> word;

        add_word(word);
    }

    int ans = 0;
    for (int i = 0; i < num_prefixes; i++)
    {
        string prefix;
        cin >> prefix;
        if (find_prefix(prefix))
            ans++;
    }

    cout << ans;
    return 0;
}